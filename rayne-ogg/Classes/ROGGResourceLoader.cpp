//
//  ROGGResourceLoader.cpp
//  rayne-ogg
//
//  Copyright 2014 by Überpixel. All rights reserved.
//  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
//  documentation files (the "Software"), to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
//  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
//  PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
//  FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#include "ROGGResourceLoader.h"
#include <RALAudioResource.h>

namespace RN
{
	namespace ogg
	{
		#include "stb_vorbis.c"
		
		RNDefineMeta(OggResourceLoader, RN::ResourceLoader)
			
		// ---------------------
		// MARK: -
		// MARK: OggResourceLoader
		// ---------------------
		
		OggResourceLoader::OggResourceLoader() :
		ResourceLoader(RN::AudioResource::GetMetaClass())
		{
			SetFileExtensions({"ogg"});
		}
		
		void OggResourceLoader::InitialWakeUp(MetaClass *meta)
		{
			if(meta == GetMetaClass())
			{
				OggResourceLoader *loader = new OggResourceLoader();
				ResourceCoordinator::GetSharedInstance()->RegisterResourceLoader(loader);
				loader->Release();
			}
		}
		
		Asset *OggResourceLoader::Load(File *file, Dictionary *settings)
		{
			short *audioData = nullptr;
			int channels = 0;
			int sample_rate = 0;
			std::vector<uint8> fileData = file->GetBytes();
			int samples = stb_vorbis_decode_memory(fileData.data(), static_cast<unsigned int>(fileData.size()), &channels, &sample_rate, &audioData);
			
			RN::AudioResource *audio = new RN::AudioResource();
			RN::Data *data = new RN::Data(reinterpret_cast<uint8*>(audioData), samples * channels * 2);
			audio->SetRawAudioData(data, 16, sample_rate, channels);
			free(audioData);
			
			return audio;
		}
		
		bool OggResourceLoader::SupportsLoadingFile(File *file)
		{
			return true;
		}
		
		bool OggResourceLoader::SupportsBackgroundLoading()
		{
			return true;
		}
		
		uint32 OggResourceLoader::GetPriority() const
		{
			return kRNResourceCoordinatorBuiltInPriority;
		}
	}
}
