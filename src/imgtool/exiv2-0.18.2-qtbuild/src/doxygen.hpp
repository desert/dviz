// ***************************************************************** -*- C++ -*-
/*!
  @file    doxygen.hpp
  @brief   Additional documentation, this file contains no source code
  @version $Rev: 1838 $
  @author  Andreas Huggel (ahu)
           <a href="mailto:ahuggel@gmx.net">ahuggel@gmx.net</a>
  @date    07-Feb-04, ahu: created
 */
// *****************************************************************************
// ***    NOTE: doxygen.hpp is a generated file! Only edit doxygen.hpp.in    ***
// *****************************************************************************
/*!
  @mainpage Image metadata library and tools v0.18.2

  @section overview Exiv2 Overview

  %Exiv2 comprises of a C++ library and a command line utility to access image
  metadata. %Exiv2 is free software. The homepage of %Exiv2 is at
  <A HREF="http://www.exiv2.org/">http://www.exiv2.org/</A>.

  The %Exiv2 library provides
  - fast read and write access to the Exif, IPTC and XMP metadata of an image
    through %Exiv2 keys and standard C++ iterators
  - conversion of Exif and IPTC metadata to and from XMP
  - a smart IPTC implementation that does not affect data that programs like
    Photoshop store in the same image segment
  - Exif <A HREF="makernote.html">MakerNote</A> support:
    - %MakerNote tags can be accessed just like any other Exif metadata
    - a sophisticated write algorithm avoids corrupting the %MakerNote
  - extract and delete methods for Exif thumbnails (both, JPEG and TIFF thumbnails)
  - set methods for Exif thumbnails (JPEG only, TIFF thumbnails can be set from
    individual tags)
  - an easy to use and well documented API

  @section getting-started Getting started

  <A HREF="getting-started.html">A few pointers</A> to get you started with
  the %Exiv2 library without delay.

  @section metadata Metadata reference tables

  Exif and MakerNote tags
  - <A HREF="tags-exif.html">Standard Exif tags</A>
  - <A HREF="tags-canon.html">Canon MakerNote tags</A>
  - <A HREF="tags-fujifilm.html">Fujifilm MakerNote tags</A>
  - <A HREF="tags-minolta.html">Minolta MakerNote tags</A>
  - <A HREF="tags-nikon.html">Nikon MakerNote tags</A>
  - <A HREF="tags-olympus.html">Olympus MakerNote tags</A>
  - <A HREF="tags-panasonic.html">Panasonic MakerNote tags</A>
  - <A HREF="tags-pentax.html">Pentax MakerNote tags</A>
  - <A HREF="tags-sigma.html">Sigma/Foveon MakerNote tags</A>
  - <A HREF="tags-sony.html">Sony MakerNote tags</A>

  IPTC datasets
  - <A HREF="tags-iptc.html">IPTC datasets</A>

  XMP properties
  - <a href="tags-xmp-dc.html">dc schema</a>
  - <a href="tags-xmp-xmp.html">xmp schema</a>
  - <a href="tags-xmp-xmpRights.html">xmpRights schema</a>
  - <a href="tags-xmp-xmpMM.html">xmpMM schema</a>
  - <a href="tags-xmp-xmpBJ.html">xmpBJ schema</a>
  - <a href="tags-xmp-xmpTPg.html">xmpTPg schema</a>
  - <a href="tags-xmp-xmpDM.html">xmpDM schema</a>
  - <a href="tags-xmp-pdf.html">pdf schema</a>
  - <a href="tags-xmp-photoshop.html">photoshop schema</a>
  - <a href="tags-xmp-crs.html">crs schema</a>
  - <a href="tags-xmp-tiff.html">tiff schema</a>
  - <a href="tags-xmp-exif.html">exif schema</a>
  - <a href="tags-xmp-aux.html">aux schema</a>
  - <a href="tags-xmp-iptc.html">Iptc4xmpCore schema</a>
  - <a href="tags-xmp-digiKam.html">digiKam schema</a>
  - <a href="tags-xmp-MicrosoftPhoto.html">MicrosoftPhoto schema</a>

  @section formats File Formats

  <P>See the <A HREF="http://dev.exiv2.org/wiki/exiv2/Supported_image_formats">list of supported image formats</A>
  in the Wiki and the <A HREF="crw-mapping.html">Canon CRW mapping</A>.</P>

  @section supp Support

  <p>All project resources are accessible from the
  <A HREF="http://dev.exiv2.org/wiki/exiv2">project website</A>.</p>

  <p>Please send feedback or queries to the %Exiv2 forum. For new bug reports
  and feature requests, please open an issue.</p>

  @section license License

  <P>Copyright (C) 2004-2009 Andreas Huggel <ahuggel@gmx.net></P>

  <P>%Exiv2 is free software; you can redistribute it and/or modify it under the
  terms of the <a href="gpl-license.html">GNU General Public License</a> as
  published by the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.</P>

  <P>Alternatively, %Exiv2 is also available with a commercial license, which
  allows it to be used in closed-source projects.
  <A HREF="mailto:ahuggel@gmx.net">Contact me</A> for more information.</P>

  <P>%Exiv2 is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
  A PARTICULAR PURPOSE.  See the GNU General Public License for more
  details.</P>

  <P>You should have received a copy of the GNU General Public License along
  with this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin Street, 5th Floor, Boston, MA 02110-1301 USA.</P>
*/
/*!
  @example addmoddel.cpp
  Sample usage of high-level metadata operations.
 */
/*!
  @example exifprint.cpp
  Sample program to print Exif data from an image.
 */
/*!
  @example exifcomment.cpp
  Sample program showing how to set the Exif comment of an image.
 */
/*!
  @example iptcprint.cpp
  Sample program to print the IPTC metadata of an image
 */
/*!
  @example iptceasy.cpp
  The quickest way to access, set or modify IPTC metadata
 */
/*!
  @example xmpsample.cpp
  Sample usage of high-level XMP classes.
 */
