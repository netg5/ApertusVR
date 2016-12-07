/*MIT License

Copyright (c) 2016 MTA SZTAKI

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/

#ifndef APE_OGRERENDERPLUGINCONFIGS_H
#define APE_OGRERENDERPLUGINCONFIGS_H

#include <vector>
#include <string>
#include "ApeVector3.h"
#include "ApeQuaternion.h"
#include "ApeDegree.h"
#include "ApeRadian.h"

namespace Ape
{
	struct OgreCameraConfig
	{
		Ape::Vector3 positionOffset;
		
		Ape::Quaternion orientationOffset;

		float nearClip;

		float farClip;

		Degree fovY;

		OgreCameraConfig()
		{
			this->positionOffset = Ape::Vector3();
			this->orientationOffset = Ape::Quaternion();
			this->nearClip = 0.0f;
			this->farClip = 0.0f;
			this->fovY = 0.0f;
		}

		OgreCameraConfig(
			Ape::Vector3 positionOffset,
			Ape::Quaternion orientationOffset,
			float nearClip,
			float farClip,
			Degree fovY)
		{
			this->positionOffset = positionOffset;
			this->orientationOffset = orientationOffset;
			this->nearClip = nearClip;
			this->farClip = farClip;
			this->fovY = fovY;
		}
	};

	struct OgreViewPortConfig
	{
		OgreCameraConfig camera;

		int zOrder;

		int left;

		int top;

		int width;

		int height;

		OgreViewPortConfig()
		{
			this->camera = OgreCameraConfig();
			this->zOrder = 0;
			this->left = 0;
			this->top = 0;
			this->width = 0;
			this->height = 0;
		}

		OgreViewPortConfig(
		OgreCameraConfig camera,
		int zOrder,
		int left,
		int top,
		int width,
		int height)
		{
			this->camera = camera;
			this->zOrder = zOrder;
			this->left = left;
			this->top = top;
			this->width = width;
			this->height = height;
		}
	};

	typedef std::vector < Ape::OgreViewPortConfig > OgreViewPortConfigList;

	struct OgreRenderWindowConfig
	{
		std::string name;
		
		int monitorIndex;

		int width;

		int height;

		bool vSync;

		int vSyncInterval;

		bool fullScreen;

		int fsaa;

		std::string fsaaHint;

		int colorDepth;

		Ape::OgreViewPortConfigList viewportList;

		std::string windowHandler;

		OgreRenderWindowConfig()
		{
			this->name = "";
			this->monitorIndex = 0;
			this->width = 0;
			this->height = 0;
			this->vSync = false;
			this->vSyncInterval = 0;
			this->fullScreen = false;
			this->fsaa = 0;
			this->fsaaHint = "";
			this->colorDepth = 0;
			this->viewportList = Ape::OgreViewPortConfigList();
			this->windowHandler = "";
		}

		OgreRenderWindowConfig(std::string name,
		int monitorIndex,
		int width,
		int height,
		bool vSync,
		int vSyncInterval,
		bool fullScreen,
		int fsaa,
		int fsaaHint,
		int colorDepth,
		Ape::OgreViewPortConfigList viewportList,
		std::string windowHandler = "")
		{
			this->name = name;
			this->monitorIndex = monitorIndex;
			this->width = width;
			this->height = height;
			this->vSync = vSync;
			this->vSyncInterval = vSyncInterval;
			this->fullScreen = fullScreen;
			this->fsaa = fsaa;
			this->fsaaHint = fsaaHint;
			this->colorDepth = colorDepth;
			this->viewportList = viewportList;
			this->windowHandler = windowHandler;
		}
	};

	typedef std::vector < Ape::OgreRenderWindowConfig > OgreRenderWindowConfigList;
}

#endif
