#ifndef ALIEMCALESDTRACKFILTERTASK_H
#define ALIEMCALESDTRACKFILTERTASK_H

// $Id$

class TClonesArray;
class AliESDEvent;
class AliESDtrack;
class AliESDtrackCuts;
class AliEMCALRecoUtils;

#include "AliAnalysisTaskSE.h"
#include "AliESDtrackCuts.h"

class AliEmcalEsdTrackFilterTask : public AliAnalysisTaskSE {
 public:
  AliEmcalEsdTrackFilterTask();
  AliEmcalEsdTrackFilterTask(const char *name);
  virtual ~AliEmcalEsdTrackFilterTask();

  void UserCreateOutputObjects();
  void UserExec(Option_t *option);
   
  void SetDist(Double_t d)                       { fDist             = d;    }
  void SetDoPropagation(Bool_t b)                { fDoPropagation    = b;    }
  void SetDoSpdVtxConstrain(Bool_t b)            { fDoSpdVtxCon      = b;    }
  void SetHybridTrackCuts(AliESDtrackCuts *cuts) { fHybridTrackCuts  = cuts; }
  void SetIncludeNoITS(Bool_t f)                 { fIncludeNoITS     = f;    }
  void SetTrackCuts(AliESDtrackCuts *cuts)       { fEsdTrackCuts     = cuts; }
  void SetTracksName(const char *name)           { fTracksName       = name; }

 protected:
  AliESDtrackCuts   *fEsdTrackCuts;      // esd track cuts
  Bool_t             fDoSpdVtxCon;       // if true then do vertex constraint
  AliESDtrackCuts   *fHybridTrackCuts;   // hybrid track cuts
  TString            fTracksName;        // name of tracks 
  Bool_t             fIncludeNoITS;      // includes tracks with failed ITS refit
  Bool_t             fDoPropagation;     // propagate all hybrid tracks to EMCal surface
  Double_t           fDist;              // distance to surface (440cm default)
  AliESDEvent       *fEsdEv;             //!esd event
  TClonesArray      *fTracks;            //!track array

 private:
  AliEmcalEsdTrackFilterTask(const AliEmcalEsdTrackFilterTask&);            // not implemented
  AliEmcalEsdTrackFilterTask &operator=(const AliEmcalEsdTrackFilterTask&); // not implemented

  ClassDef(AliEmcalEsdTrackFilterTask, 1); // Class to constrain TPC tracks to SPD vertex
};

#endif
