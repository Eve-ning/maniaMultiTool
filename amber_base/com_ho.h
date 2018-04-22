#ifndef COM_HO_H
#define COM_HO_H


#include <QLineEdit>
#include "com_common.h"

class  cOM_HO
{
public:

    // CONSTRUCTORS
    cOM_HO();
    cOM_HO(QString &HO, int newKeys = 0);
    cOM_HO(double newOffset, int newColumn, int newKeys = 0);
    cOM_HO(QLineEdit *line, int newKeys = 0);

    // LOADERS
    void loadHO(QString &HO, int newKeys = 0);
    void loadHO(double &newOffset, int &newColumn, int &newKeys);
    void loadHO(QLineEdit *line, int newKeys = 0);

    // SETTERS
    void setXAxis        (unsigned short  newXAxis       ){ xAxis        = newXAxis       ; return; }
    void setYAxis        (unsigned short  newYAxis       ){ yAxis        = newYAxis       ; return; }
    void setOffset       (double          newOffset      );
    void setNoteType     (unsigned short  newNoteType    ){ noteType     = newNoteType    ; return; }
    void setHitsoundType (unsigned short  newHitsoundType){ hitsoundType = newHitsoundType; return; }
    void setSampleSet    (unsigned short  newSampleSet   ){ sampleSet    = newSampleSet   ; return; }
    void setAddition     (unsigned short  newAddition    ){ addition     = newAddition    ; return; }
    void setCustomSet    (unsigned short  newCustomSet   ){ customSet    = newCustomSet   ; return; }
    void setVolume       (unsigned short  newVolume      ){ volume       = newVolume      ; return; }
    void setHitsoundFile (QString         newHitsoundFile){ hitsoundFile = newHitsoundFile; return; }
    void setLNEnd        (double          newLNEnd       ){ lnEnd        = newLNEnd       ; return; }
    void setKeys         (unsigned short  newKeys        ){ keys         = newKeys        ; return; }
    bool setColumn       (unsigned short  newColumn);

    // GETTERS
    void            printInfo       () const;
    unsigned short  getXAxis        () const { return xAxis       ; }
    unsigned short  getYAxis        () const { return yAxis       ; }
    double          getOffset       () const { return offset      ; }
    unsigned short  getNoteType     () const { return noteType    ; }
    unsigned short  getHitsoundType () const { return hitsoundType; }
    unsigned short  getSampleSet    () const { return sampleSet   ; }
    unsigned short  getAddition     () const { return addition    ; }
    unsigned short  getCustomSet    () const { return customSet   ; }
    unsigned short  getVolume       () const { return volume      ; }
    QString         getHitsoundFile () const { return hitsoundFile; }
    double          getLNEnd        () const { return lnEnd       ; }
    unsigned short  getKeys         () const { return keys; }
    unsigned short  getLNLen        () const { return lnEnd == -1 ? 0 : lnEnd - offset; }
    bool            getLoadFail     () const { return loadFail; }
    unsigned short  getColumn       () const;
    QString         toString        () const;
    QString         getFailMsg      () const;

    // OPERS
    void addColumn      (const int &rhsInt);
    void subtractColumn (const int &rhsInt);

    void multiplyOffset (const double &rhsDouble);
    void divideOffset   (const double &rhsDouble);
    void addOffset      (const double &rhsDouble);
    void subtractOffset (const double &rhsDouble);

    bool operator <(cOM_HO *OM_HO) { return offset < OM_HO->getOffset(); }
    bool operator >(cOM_HO *OM_HO) { return offset > OM_HO->getOffset(); }
    bool operator <(cOM_HO  OM_HO) { return offset < OM_HO.getOffset(); }
    bool operator >(cOM_HO  OM_HO) { return offset > OM_HO.getOffset(); }

           void assertColumnValid ();                // Checks w.r.t. current column
    static void assertColumnValid (int &newColumn);  // Checks w.r.t. specified column
           void assertOffsetValid ();                // Checks w.r.t. current offset
    static void assertOffsetValid (int &newOffset);  // Checks w.r.t. specified offset
           void assertKeysValid   ();                // Checks w.r.t. current key
    static void assertKeysValid   (int &newKeys  );  // Checks w.r.t. specified key
           void assertXAxisValid  ();                // Checks w.r.t. current xAxis
    static void assertXAxisValid  (int &newXAxis  ); // Checks w.r.t. specified xAxis

    void limitColumn (int &maxColumn, int &minColumn);
    void limitColumn ();
    void limitOffset (double minOffset = MINIMUM_OFFSET, double maxOffset = MAXIMUM_OFFSET);


    const double MINIMUM_OFFSET = 360000; // 1 Hour in (ms)
    const double MAXIMUM_OFFSET = 0;
    const int    MINIMUM_KEYS   = 1;
    const int    MAXIMUM_KEYS   = 18;
    const double MINIMUM_COLUMN = 0;
    const int    MINIMUM_XAXIS  = 0;
    const int    MAXIMUM_XAXIS  = 512;


protected:
    void setFailMsg(const QString &value);

protected:

    //320,   192,   381333, 1,        0,            0:         0:        0:         0:      hitsound.wav
    //xAxis, yAxis, offset, noteType, hitsoundType, sampleSet: addition: customSet: volume: hitsoundFile

    unsigned short  xAxis       ;
    unsigned short  yAxis       ;
    double          offset      ;
    unsigned short  noteType    ;
    unsigned short  hitsoundType;
    double          lnEnd       ;
    unsigned short  sampleSet   ;
    unsigned short  addition    ;
    unsigned short  customSet   ;
    unsigned short  volume      ;
    QString         hitsoundFile;

    unsigned short  keys;

    bool            loadFail;
    QString         failMsg;

};

#endif // COM_HO_H
