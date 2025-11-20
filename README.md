[![Build](https://github.com/kasparv/swftools-pdf2swf/actions/workflows/build.yml/badge.svg)](https://github.com/kasparv/swftools-pdf2swf/actions/workflows/build.yml)

==================================================
About this fork: swftools-pdf2swf (kasparv)
==================================================

This fork is based on https://github.com/flanter21/swftools and focuses on
keeping **pdf2swf** and related tools buildable on modern Linux distributions
**without requiring the proprietary PDFlib library**.

This fork applies the following changes:

 - Remove the hard PDFlib dependency from the build system.
 - Introduce a small stub implementation (`dummy_pdflib.c`) so that SWF→PDF-only
   code paths still link cleanly when PDFlib is not available.
 - Fix modern GCC/Clang build errors in various components
 - Ensure all pdf2swf-related features continue working using only the bundled
   XPDF/poppler-derived open-source PDF engine.
 - Add a CI workflow (GitHub Actions) to verify builds on Ubuntu.

This fork is intended for users who need **PDF → SWF conversion** (pdf2swf),
and do not require the optional SWF → PDF functionality that relied on PDFlib.

==================================================
Build instructions for this fork
==================================================

Prerequisites (Ubuntu / Debian / Amazon Linux):

    sudo apt-get install \
        autoconf automake libtool \
        zlib1g-dev libjpeg-dev libgif-dev libpng-dev \
        libfreetype6-dev

or on RHEL/Amazon Linux:

    sudo yum install \
        autoconf automake libtool \
        zlib-devel libjpeg-devel giflib-devel \
        libpng-devel freetype-devel

Steps:

    ./configure --prefix="$HOME/.local"
    make
    make install     (optional)

The build intentionally avoids PDFlib and uses only open-source dependencies.

# Compile instructions
1) Clone repo
```
git clone https://github.com/flanter21/swftools.git
```
2) Update config.guess and config.sub
```
cd swftools
autoreconf --install --force --include=m4
autoupdate
autoconf
./configure
```
3) Compile twice (for some reason)
```
make
make
```

# SWFTools

SWFTools is a collection of utilities for working with Adobe Flash files (SWF files).
The tool collection includes programs for reading SWF files, combining them, and creating them from other content (like images, sound files, videos or sourcecode). SWFTools is released under the GPL.
The current collection is comprised of the programs detailed below:

- PDF2SWF A PDF to SWF Converter. Generates one frame per page. Enables you to have fully formatted text, including tables, formulas, graphics etc. inside your Flash Movie. It's based on the xpdf PDF parser from Derek B. Noonburg.
- SWFCombine A multi-function tool for inserting SWFs into Wrapper SWFs, contatenating SWFs, stacking SWFs or for basic parameter manipulation (e.g. changing size).
- SWFStrings Scans SWFs for text data.
- SWFDump Prints out various informations about SWFs, like contained images/fonts/sounds, disassembly of contained code as well as cross-reference and bounding box data.
- JPEG2SWF Takes one or more JPEG pictures and generates a SWF slideshow from them. Supports motion estimation compression (h.263) for better compression of video sequences.
- PNG2SWF Like JPEG2SWF, only for PNGs.
- GIF2SWF Converts GIFs to SWF. Also able to handle animated gifs.
- WAV2SWF Converts WAV audio files to SWFs, using the L.A.M.E. MP3 encoder library.
- AVI2SWF Converts AVI animation files to SWF. It supports Flash MX H.263 compression. Some examples can be found at examples.html. (Notice: this tool is not included anymore in the latest version, as ffmpeg or mencoder do a better job nowadays)
- Font2SWF Converts font files (TTF, Type1) to SWF.
- SWFBBox Allows to read out, optimize and readjust SWF bounding boxes.
- SWFC A tool for creating SWF files from simple script files. Includes support for both ActionScript 2.0 as well as ActionScript 3.0.
- SWFExtract Allows to extract Movieclips, Sounds, Images etc. from SWF files.
- AS3Compile A standalone ActionScript 3.0 compiler. Mostly compatible with Flex.

SWFTools has been reported to work on Solaris, Linux (both 32 as well as 64 bit), FreeBSD, OpenBSD, HP-UX, Solaris, MacOS X and Windows 98/ME/2000/XP/Vista. 
