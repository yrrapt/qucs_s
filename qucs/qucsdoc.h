/***************************************************************************
                                 qucsdoc.h
                                -----------
    begin                : Wed Sep 3 2003
    copyright            : (C) 2003 by Michael Margraf
    email                : michael.margraf@alumni.tu-berlin.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QUCSDOC_H
#define QUCSDOC_H

#include <qstring.h>

class QucsApp;
class QPainter;

extern const char *smallsave_xpm[];// icon for unsaved files (diskette)
extern const char *empty_xpm[];    // provides same height than "smallsave_xpm"


class QucsDoc {
public: 
  QucsDoc(QucsApp*, const QString&);
  virtual ~QucsDoc() {};

  virtual void setName(const QString&) {};
  virtual bool load() { return true; };
  virtual int  save() { return 0; };
  virtual void print(QPainter*, bool) {};
  virtual void becomeCurrent(bool) {};

  QString DocName;
  QString DataSet;     // name of the default dataset
  QString DataDisplay; // name of the default data display

  QucsApp *App;
  bool DocChanged;
  bool SimOpenDpl;  // open data display after simulation ?
  int  showBias;    // -1=no, 0=calculation running, >0=show DC bias points
  bool GridOn;
};

#endif
