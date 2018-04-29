#ifndef cOM_TPLIST_H
#define cOM_TPLIST_H

#include <cstdlib>
#include "com_tp.h"
#include <QTextBrowser>
#include <QLineEdit>
#include <QPlainTextEdit>

class  cOM_TPList
{
public:
    // CONSTRUCTORS
    cOM_TPList()                          ;
    cOM_TPList(QList<cOM_TP> newOM_TPList);
    cOM_TPList(QTextBrowser *tb)          ;
    cOM_TPList(QLineEdit *line)           ;
    cOM_TPList(QPlainTextEdit *pte)       ;
    cOM_TPList(QString str)               ;
    cOM_TPList(QStringList strList)       ;

    operator QStringList() const { return toString(); }

    // LOADERS
    void loadTPList(QList<cOM_TP>  newOM_TPList);
    void loadTPList(QTextBrowser   *tb);
    void loadTPList(QLineEdit      *line);
    void loadTPList(QPlainTextEdit *pte);
    void loadTPList(QString        &str);
    void loadTPList(QStringList    &str);

    // SETTERS
    void setOffsetList(QList<double> newOffsetList);
    void setCodeList  (QList<double> newCodeList);
    void setValueList (QList<double> newValueList);

    omInfo getInfo();

    // GETTERS
    QList<double> getOffsetList    (const omInfo &info = omInfo(true)) const;
    QList<double> getCodeList      (const omInfo &info = omInfo(true)) const;
    QList<double> getValueList     (const omInfo &info = omInfo(true)) const;
    QList<double> getLengthList    (const omInfo &info = omInfo(true)) const;
    QList<double> getDistanceList  (const omInfo &info = omInfo(true)) const;
    QList<double> getUnqOffsetList (const omInfo &info = omInfo(true)) const;

    cOM_TPList splitByType (const omInfo &info) const;

    double getMinOffset  () const;
    double getMaxOffset  () const;
    double getMinValue   (const omInfo &info) const;
    double getMaxValue   (const omInfo &info) const;
    double getLength     () const;
    double getLength     (int index);
    int    getSize       (const omInfo &info = omInfo(true)) const;
    double getAverage    (const omInfo &info) const;
    double getDistance   (const omInfo &info) const;
    double getDistance   (int index);
    bool   getLoadFail   () const { return loadFail; }
    QStringList toString () const;

    // OPERS
    cOM_TP   operator [](int i) const;
    cOM_TP & operator [](int i);

    void multiplyValue  (const cOM_TPList rhsOM_TPList, bool limitFlag = false);
    void divideValue    (const cOM_TPList rhsOM_TPList, bool limitFlag = false);
    void addValue       (const cOM_TPList rhsOM_TPList, bool limitFlag = false);
    void subtractValue  (const cOM_TPList rhsOM_TPList, bool limitFlag = false);

    void multiplyValue  (const double rhsDouble, bool limitFlag = false);
    void divideValue    (const double rhsDouble, bool limitFlag = false);
    void addValue       (const double rhsDouble, bool limitFlag = false);
    void subtractValue  (const double rhsDouble, bool limitFlag = false);

    void multiplyOffset (const double rhsDouble, bool limitFlag = false);
    void divideOffset   (const double rhsDouble, bool limitFlag = false);
    void addOffset      (const double rhsDouble, bool limitFlag = false);
    void subtractOffset (const double rhsDouble, bool limitFlag = false);

    void zero    ();

    // SORTING
    void sortOffset (const bool isAscending = true);

    // MISC
    void append     (cOM_TP newOM_TP) { OM_TPList.append(newOM_TP); }
    void append     (cOM_TPList newOM_TPList);
    void deleteIndex(unsigned  index) { OM_TPList.removeAt(index); }
    bool isEmpty    () const;

    // LIMITS VALUES DEPENDING ON THEIR ISBPM VALUE
    void limitValues(double maxSV = 10.0, double minSV = 0.1, double maxBPM = 0, double minBPM = 0.000001); // ADD CUSTOM LIMITS
    void limitOffset(double minOffset = 0, double maxOffset = 360000);

    // ADJUSTS A TP SO THAT THE AVERAGE IS MET
    void adjustToAverage (double averageSV, int adjustIndex);

    // REMOVES TP THAT HAVE SIMILAR OFFSET
    void makeUnique ();

    void isUniform(omInfo &info);

    QList<int> indexList(omInfo &info);

protected:
    QList<cOM_TP> OM_TPList;
    bool          loadFail;
};

#endif // cOM_TPLIST_H