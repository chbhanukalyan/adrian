/*
Open Asset Import Library (ASSIMP)
----------------------------------------------------------------------

Copyright (c) 2006-2008, ASSIMP Development Team
All rights reserved.

Redistribution and use of this software in source and binary forms, 
with or without modification, are permitted provided that the 
following conditions are met:

* Redistributions of source code must retain the above
  copyright notice, this list of conditions and the
  following disclaimer.

* Redistributions in binary form must reproduce the above
  copyright notice, this list of conditions and the
  following disclaimer in the documentation and/or other
  materials provided with the distribution.

* Neither the name of the ASSIMP team, nor the names of its
  contributors may be used to endorse or promote products
  derived from this software without specific prior
  written permission of the ASSIMP Development Team.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------
*/


#ifndef OBJ_FILEPARSER_H_INC
#define OBJ_FILEPARSER_H_INC

#include <vector>
#include <string>
#include <map>
#include "../include/aiTypes.h"

namespace Assimp
{

namespace ObjFile
{
struct Model;
struct Object;
struct Material;
struct Point3;
struct Point2;
}
class ObjFileImporter;

///	\class	ObjFileParser
///	\brief	Parser for a obj waveform file
class ObjFileParser
{
public:
	static const size_t BUFFERSIZE = 1024;
	typedef std::vector<char> DataArray;
	typedef std::vector<char>::iterator DataArrayIt;
	typedef std::vector<char>::const_iterator ConstDataArrayIt;

public:
	///	\brief	Constructor with data array.
	ObjFileParser(std::vector<char> &Data, const std::string &strAbsPath, const std::string &strModelName, IOSystem* io);
	///	\brief	Destructor
	~ObjFileParser();
	///	\brief	Model getter.
	ObjFile::Model *GetModel() const;

private:
	///	Parse the loadedfile
	void parseFile();
	///	Method to copy the new delimited word in the current line.
	void copyNextWord(char *pBuffer, size_t length);
	///	Method to copy the new line.
	void copyNextLine(char *pBuffer, size_t length);
	///	Stores the following 3d vector.
	void getVector3( std::vector<aiVector3D> &point3d_array );
	///	Stores the following 3d vector.
	void getVector2(std::vector<aiVector2D> &point2d_array);
	///	Stores the following face.
	void getFace();
	void getMaterialDesc();
	///	Gets a comment.
	void getComment();
	/// Gets a a material library.
	void getMaterialLib();
	/// Creates a new material.
	void getNewMaterial();
	/// Gets the groupname from file.
	void getGroupName();
	/// Gets the group number from file.
	void getGroupNumber();
	///
	int getMaterialIndex( const std::string &strMaterialName );
	///
	void getObjectName();
	///
	void createObject(const std::string &strObjectName);
	///	Error report in token
	void reportErrorTokenInFace();

private:
	///	Default material name
	static const std::string DEFAULT_MATERIAL;/* = "defaultmaterial";*/
	//!	Absolute filepath to model
	std::string m_strAbsPath;
	//!	Iterator to current position in buffer
	DataArrayIt m_DataIt;
	//!	Iterator to end position of buffer
	DataArrayIt m_DataItEnd;
	//!	Pointer to model instance
	ObjFile::Model *m_pModel;
	//!	Current line (for debugging)
	unsigned int m_uiLine;
	//!	Helper buffer
	char m_buffer[BUFFERSIZE];

	IOSystem* io;
};

}	// Namespace Assimp

#endif
