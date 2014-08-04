//
//  ROGGResourceLoader.h
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

#ifndef __RAYNE_OGG_RESOURCELOADER__
#define __RAYNE_OGG_RESOURCELOADER__

#include <Rayne/Rayne.h>

namespace RN
{
	namespace ogg
	{
		class OggResourceLoader : public ResourceLoader
		{
		public:
			OggResourceLoader();
			
			Asset *Load(File *file, Dictionary *settings) override;
			
			bool SupportsBackgroundLoading() override;
			bool SupportsLoadingFile(File *file) override;
			
			uint32 GetPriority() const override;
			
			static void InitialWakeUp(MetaClass *meta);
			
		private:

			RNDeclareMeta(OggResourceLoader)
		};
	}
}

#endif /* __RAYNE_OGG_RESOURCELOADER__ */
