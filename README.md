# Unreal 5 plugin for TUIO

This is a very basic plugin integrating TUIO in Unreal 5. It exposes a `TUIOReceiver` component that provides TUIO11 [Listener events](blob/main/Source/ThirdParty/TUIO11/TUIO11_CPP/TUIO/TuioListener.h).

## Plugin setup

Clone the plugin in the `Plugins` at the root of your unreal project.

For your convenience, the plugin contains pre-compiled binaries for Windows x64, in the `binaries` folder.
If you don't want to use the pre-compiled binaries, or if you target another platform than Windows x64, you can recompile libTUIO11 and edit [Source/TUIO/TUIO.Build.cs](blob/main/Source/TUIO/TUIO.Build.cs) to use your binaries.

## Usage

Create an actor blueprint and attach a `TUIOReceiver` component to it. In the Event Graph you can use events from the component named `On<Add/Update/Remove><Object/Cursor/Blob>`. The events have a struct payload with contains the touch position, speed, session ID and source ID.

## Acknowledgements

This work is based on [TUIO](http://www.tuio.org/)'s reference implementation ([TUIO11_CPP](https://github.com/mkalten/TUIO11_CPP), Martin Kaltenbrunner) and was inspired by the (UE-OSC)[https://github.com/monsieurgustav/UE-OSC] plugin. Thanks to the authors.

## License

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA02111-1307USA
