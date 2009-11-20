#include "AbstractItem.h"
#include <QDebug>
#include <QMetaProperty>

#include "TextItem.h"
#include "TextBoxItem.h"
#include "BoxItem.h"
#include "ImageItem.h"
#include "VideoFileItem.h"
#include "BackgroundItem.h"
#include "OutputViewItem.h"
#include "ItemFactory.h"

QString AbstractItem::guessTitle(QString field)
{
	static QRegExp rUpperCase = QRegExp("([a-z])([A-Z])");
	static QRegExp rFirstLetter = QRegExp("([a-z])");
	static QRegExp rLetterNumber = QRegExp("([a-z])([0-9])");
	//static QRegExp rUnderScore 
	//$name =~ s/([a-z])_([a-z])/$1.' '.uc($2)/segi;
	
	QString tmp = field;
	tmp.replace(rUpperCase,"\\1 \\2");
	if(tmp.indexOf(rFirstLetter) == 0)
	{
		QChar x = tmp.at(0);
		tmp.remove(0,1);
		tmp.prepend(QString(x).toUpper());
	}
	
	tmp.replace(rLetterNumber,"\\1 #\\2");
	//$name =~ s/^([a-z])/uc($1)/seg;
	
// 	$name =~ s/\/([a-z])/'\/'.uc($1)/seg;
// 	$name =~ s/\s([a-z])/' '.uc($1)/seg;
// 	$name =~ s/\s(of|the|and|a)\s/' '.lc($1).' '/segi;
// 	$name .= '?' if $name =~ /^is/i;
// 	$name =~ s/id$//gi;
// 	my $chr = '#';
// 	$name =~ s/num$/$chr/gi; 
// 	$name =~ s/datetime$/Date\/Time/gi;
// 	$name =~ s/\best\b/Est./gi;

	return tmp;
	

}

AbstractItem::AbstractItem() :
	  m_isBeingLoaded(false)
	, m_isChanged(false)
	, m_revision(0)
{}

ITEM_PROPSET(AbstractItem, ItemId,   quint32, itemId);
ITEM_PROPSET(AbstractItem, ItemName, QString, itemName);

void AbstractItem::setChanged(QString name, QVariant value, QVariant oldValue)
{
	if(!isBeingLoaded())
	{
		if(value != oldValue)
		{
			m_revision ++;
			//qDebug() << "AbstractItem::setChanged: itemName:"<<itemName()<<", name:"<<name<<", value:"<<value;
			emit itemChanged(name,value,oldValue);
			m_isChanged = true;
		}
	}
}

void AbstractItem::clearIsChanged() { m_isChanged = false; }

void AbstractItem::setBeingLoaded(bool flag) { m_isBeingLoaded = flag; }

AbstractItem * AbstractItem::clone() const
{
	return cloneTo(new AbstractItem());
}

AbstractItem * AbstractItem::cloneTo(AbstractItem *item) const
{
	item->setBeingLoaded(true);

	//qDebug() << "AbstractItem::clone():"<<itemName()<<": Cloning item.";

	// So we dont have to engineer our own method of tracking
	// properties, just assume all inherited objects delcare the relevant
	// properties using Q_PROPERTY macro
	const QMetaObject *metaobject = metaObject();
	int count = metaobject->propertyCount();
	for (int i=0; i<count; ++i)
	{
		QMetaProperty metaproperty = metaobject->property(i);
		const char *name = metaproperty.name();
		QVariant value = property(name);
		//qDebug() << "AbstractItem::clone():"<<itemName()<<": prop:"<<name<<", value:"<<value;
		item->setProperty(name,value);
	}

	item->setItemId(ItemFactory::nextId());
	//newItem->setItemName(QString("NewItem%1").arg(bg->itemId()));
	QString name = item->itemName();
	static QRegExp rxEndingDigits("(\\d+)$");
	name.replace(rxEndingDigits,QString::number(item->itemId()));
	item->setItemName(name);
	
	item->setBeingLoaded(false);
	
	//qDebug() << "AbstractItem::clone():"<<itemName()<<": Done cloning.";

	return item;
}

QByteArray AbstractItem::toByteArray() const
{
	QByteArray array;
	QDataStream stream(&array, QIODevice::WriteOnly);
	QVariantMap map;
	
	// So we dont have to engineer our own method of tracking
	// properties, just assume all inherited objects delcare the relevant
	// properties using Q_PROPERTY macro
	const QMetaObject *metaobject = metaObject();
	int count = metaobject->propertyCount();
	for (int i=0; i<count; ++i)
	{
		QMetaProperty metaproperty = metaobject->property(i);
		const char *name = metaproperty.name();
		QVariant value = property(name);
// 		qDebug() << "AbstractItem::toByteArray():"<<itemName()<<": prop:"<<name<<", value:"<<value;
		//item->setProperty(name,value);
		map[name] = value;
	}

	map["AbstractItem.ClassName"] = metaobject->className();
	stream << map;
	return array; 
}
/* static */
AbstractItem * AbstractItem::fromByteArray(QByteArray &array)
{
	
	QDataStream stream(&array, QIODevice::ReadOnly);
	QVariantMap map;
	stream >> map;
	
	QString className = map["AbstractItem.ClassName"].toString();
	
	//qDebug("Slide::fromXml(): Found an element, tag name=%s", element.tagName().toAscii().constData());
	// create the right kind of content
	AbstractItem * content = 0;
	if (className == "TextItem")
		content = new TextItem();
	else 
	if (className == "TextBoxItem")
		content = new TextBoxItem();
	else 
	if (className == "BoxItem")
		content = new BoxItem();
	else
	if (className == "ImageItem")
		content = new ImageItem();
	else 
	if (className == "VideoFileItem")
		content = new VideoFileItem();
	else 
	if (className == "BackgroundItem")
		content = new BackgroundItem();
	else
	if (className == "OutputViewItem")
		content = new OutputViewItem();
	else
	{
		qWarning("AbstractItem::fromByteArray: Unknown class name '%s'", qPrintable(className));
		return 0;
	}

	content->setBeingLoaded(true);
	
	content->loadVariantMap(map);
	
	content->setBeingLoaded(false);
	return content;
}

void AbstractItem::loadVariantMap(QVariantMap &map)
{
	// So we dont have to engineer our own method of tracking
	// properties, just assume all inherited objects delcare the relevant
	// properties using Q_PROPERTY macro
	const QMetaObject *metaobject = metaObject();
	int count = metaobject->propertyCount();
	for (int i=0; i<count; ++i)
	{
		QMetaProperty metaproperty = metaobject->property(i);
		const char *name = metaproperty.name();
		QVariant value = map[name];
		//qDebug() << "AbstractItem::clone():"<<itemName()<<": prop:"<<name<<", value:"<<value;
		if(value.isValid())
			setProperty(name,value);
		else
			qDebug() << "AbstractItem::loadByteArray: Unable to load property for "<<name<<", got invalid property from map";
	}
}

quint32 AbstractItem::valueKey()
{
	m_valueKeyTmp.clear();
	QDataStream b(&m_valueKeyTmp, QIODevice::WriteOnly);
	
	const QMetaObject *metaobject = metaObject();
	int count = metaobject->propertyCount();
	for (int i=0; i<count; ++i)
	{
		QMetaProperty metaproperty = metaobject->property(i);
		const char *name = metaproperty.name();
		if(strcmp(name,"objectName") != 0 &&
			strcmp(name,"itemId") != 0 &&
			strcmp(name,"itemName") != 0)
		{
			QVariant value = property(name);
			b << name;
			b << value.toString();
		}
	}
	
	quint32 val = 0;
	const char *data = m_valueKeyTmp.constData();
	for(int i=0;i<m_valueKeyTmp.size();i++)
	{
		val += data[i];
	}
	//qDebug() << "Item:"<<itemName()<<": int:"<<val<<" (size:"<<m_valueKeyTmp.size()<<")";
	
	//return m_valueKeyTmp.constData();
	return val;
}

bool AbstractItem::fromXml(QDomElement & pe)
{
	setBeingLoaded(true);

	// restore content properties
	QString text = pe.firstChildElement("item-name").text();
	setItemName(text);

	quint32 id = pe.firstChildElement("item-id").text().toInt();
	setItemId(id);

	setBeingLoaded(false);

	return true;
}

void AbstractItem::toXml(QDomElement & pe) const
{
	// Save general item properties
	pe.setTagName("item");
	QDomDocument doc = pe.ownerDocument();
	QDomElement domElement;
	QDomText text;
	QString valueStr;

	valueStr.setNum(itemId());
	domElement= doc.createElement("item-id");
	pe.appendChild(domElement);
	text = doc.createTextNode(valueStr);
	domElement.appendChild(text);

	domElement= doc.createElement("item-name");
	pe.appendChild(domElement);
	text = doc.createTextNode(itemName());
	domElement.appendChild(text);

}

