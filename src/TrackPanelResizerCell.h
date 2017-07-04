/**********************************************************************

 Audacity: A Digital Audio Editor

 TrackPanelResizerCell.h

 Paul Licameli split from TrackPanel.cpp

 **********************************************************************/

#ifndef __AUDACITY_TRACK_PANEL_RESIZER_CELL__
#define __AUDACITY_TRACK_PANEL_RESIZER_CELL__

#include "tracks/ui/CommonTrackPanelCell.h"

class TrackPanelResizerCell : public CommonTrackPanelCell
{
   TrackPanelResizerCell(const TrackPanelResizerCell&) = delete;
   TrackPanelResizerCell &operator= (const TrackPanelResizerCell&) = delete;
public:

   explicit
   TrackPanelResizerCell( std::shared_ptr<Track> pTrack );

   HitTestResult HitTest
   (const TrackPanelMouseEvent &event,
    const AudacityProject *pProject) override;

   std::shared_ptr<Track> FindTrack() override { return mpTrack.lock(); };
private:
   friend class TrackPanelCellIterator;
   std::weak_ptr<Track> mpTrack;
   bool mBetweenTracks {};
};

#endif
