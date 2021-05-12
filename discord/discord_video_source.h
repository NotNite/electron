#ifndef DISCORD_DISCORD_VIDEO_SOURCE_H_
#define DISCORD_DISCORD_VIDEO_SOURCE_H_

#include <memory>
#include <mutex>

#include "base/macros.h"
#include "discord/electron_video_shared.h"
#include "third_party/blink/public/web/modules/mediastream/media_stream_video_source.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/webrtc/api/media_stream_interface.h"

namespace blink {

using DiscordFrameReleaseCB = void (*)(void*);
using discord::media::electron::DiscordFrame;

class MODULES_EXPORT MediaStreamDiscordVideoSource
    : public MediaStreamVideoSource {
 public:
  MediaStreamDiscordVideoSource(const std::string& streamId);
  ~MediaStreamDiscordVideoSource() override;

  static void OnFrame(const std::string& streamId,
                      const DiscordFrame& frame,
                      DiscordFrameReleaseCB releaseCB,
                      void* userData);

 protected:
  // Implements MediaStreamVideoSource.
  void StartSourceImpl(VideoCaptureDeliverFrameCB frame_callback,
                       EncodedVideoFrameCB encoded_frame_callback) override;
  void StopSourceImpl() override;

 private:
  DISALLOW_COPY_AND_ASSIGN(MediaStreamDiscordVideoSource);

  class VideoSourceDelegate;
  scoped_refptr<VideoSourceDelegate> delegate_;
  std::string stream_id_;

  static std::unordered_map<std::string, scoped_refptr<VideoSourceDelegate>>*
      by_stream_id_;
  static std::mutex stream_mutex_;
};
}  // namespace blink

#endif  // DISCORD_DISCORD_VIDEO_SOURCE_H_
