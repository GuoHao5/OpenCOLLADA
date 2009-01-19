/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYCUT_H__
#define __MayaDM_POLYCUT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
class PolyCut : public PolyModifierWorld
{
public:
public:
	PolyCut(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polyCut"){}
	virtual ~PolyCut(){}
	void setCutPlaneCenter(const double3& pc)
	{
		if(pc == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"setAttr \".pc\" -type \"double3\" ");
		pc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCutPlaneCenterX(double pcx)
	{
		if(pcx == 0) return;
		fprintf(mFile,"setAttr \".pc.pcx\" %f;\n", pcx);

	}
	void setCutPlaneCenterY(double pcy)
	{
		if(pcy == 0) return;
		fprintf(mFile,"setAttr \".pc.pcy\" %f;\n", pcy);

	}
	void setCutPlaneCenterZ(double pcz)
	{
		if(pcz == 0) return;
		fprintf(mFile,"setAttr \".pc.pcz\" %f;\n", pcz);

	}
	void setCutPlaneRotate(const double3& ro)
	{
		if(ro == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"setAttr \".ro\" -type \"double3\" ");
		ro.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCutPlaneRotateX(double rx)
	{
		if(rx == 0) return;
		fprintf(mFile,"setAttr \".ro.rx\" %f;\n", rx);

	}
	void setCutPlaneRotateY(double ry)
	{
		if(ry == 0) return;
		fprintf(mFile,"setAttr \".ro.ry\" %f;\n", ry);

	}
	void setCutPlaneRotateZ(double rz)
	{
		if(rz == 0) return;
		fprintf(mFile,"setAttr \".ro.rz\" %f;\n", rz);

	}
	void setCutPlaneSize(const double2& ps)
	{
		if(ps == double2(1.0, 1.0)) return;
		fprintf(mFile,"setAttr \".ps\" -type \"double2\" ");
		ps.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCutPlaneWidth(double pw)
	{
		if(pw == 0) return;
		fprintf(mFile,"setAttr \".ps.pw\" %f;\n", pw);

	}
	void setCutPlaneHeight(double ph)
	{
		if(ph == 0) return;
		fprintf(mFile,"setAttr \".ps.ph\" %f;\n", ph);

	}
	void setExtractFaces(bool ef)
	{
		if(ef == false) return;
		fprintf(mFile,"setAttr \".ef\" %i;\n", ef);

	}
	void setExtractOffset(const double3& eo)
	{
		if(eo == double3(0.5, 0.5, 0.5)) return;
		fprintf(mFile,"setAttr \".eo\" -type \"double3\" ");
		eo.write(mFile);
		fprintf(mFile,";\n");

	}
	void setExtractOffsetX(double eox)
	{
		if(eox == 0) return;
		fprintf(mFile,"setAttr \".eo.eox\" %f;\n", eox);

	}
	void setExtractOffsetY(double eoy)
	{
		if(eoy == 0) return;
		fprintf(mFile,"setAttr \".eo.eoy\" %f;\n", eoy);

	}
	void setExtractOffsetZ(double eoz)
	{
		if(eoz == 0) return;
		fprintf(mFile,"setAttr \".eo.eoz\" %f;\n", eoz);

	}
	void setDeleteFaces(bool df)
	{
		if(df == false) return;
		fprintf(mFile,"setAttr \".df\" %i;\n", df);

	}
	void setOnObject(bool oo)
	{
		if(oo == true) return;
		fprintf(mFile,"setAttr \".oo\" %i;\n", oo);

	}
	void getCutPlaneCenter()
	{
		fprintf(mFile,"\"%s.pc\"",mName.c_str());

	}
	void getCutPlaneCenterX()
	{
		fprintf(mFile,"\"%s.pc.pcx\"",mName.c_str());

	}
	void getCutPlaneCenterY()
	{
		fprintf(mFile,"\"%s.pc.pcy\"",mName.c_str());

	}
	void getCutPlaneCenterZ()
	{
		fprintf(mFile,"\"%s.pc.pcz\"",mName.c_str());

	}
	void getCutPlaneRotate()
	{
		fprintf(mFile,"\"%s.ro\"",mName.c_str());

	}
	void getCutPlaneRotateX()
	{
		fprintf(mFile,"\"%s.ro.rx\"",mName.c_str());

	}
	void getCutPlaneRotateY()
	{
		fprintf(mFile,"\"%s.ro.ry\"",mName.c_str());

	}
	void getCutPlaneRotateZ()
	{
		fprintf(mFile,"\"%s.ro.rz\"",mName.c_str());

	}
	void getCutPlaneSize()
	{
		fprintf(mFile,"\"%s.ps\"",mName.c_str());

	}
	void getCutPlaneWidth()
	{
		fprintf(mFile,"\"%s.ps.pw\"",mName.c_str());

	}
	void getCutPlaneHeight()
	{
		fprintf(mFile,"\"%s.ps.ph\"",mName.c_str());

	}
	void getExtractFaces()
	{
		fprintf(mFile,"\"%s.ef\"",mName.c_str());

	}
	void getExtractOffset()
	{
		fprintf(mFile,"\"%s.eo\"",mName.c_str());

	}
	void getExtractOffsetX()
	{
		fprintf(mFile,"\"%s.eo.eox\"",mName.c_str());

	}
	void getExtractOffsetY()
	{
		fprintf(mFile,"\"%s.eo.eoy\"",mName.c_str());

	}
	void getExtractOffsetZ()
	{
		fprintf(mFile,"\"%s.eo.eoz\"",mName.c_str());

	}
	void getDeleteFaces()
	{
		fprintf(mFile,"\"%s.df\"",mName.c_str());

	}
	void getOnObject()
	{
		fprintf(mFile,"\"%s.oo\"",mName.c_str());

	}
	void getCompId()
	{
		fprintf(mFile,"\"%s.cid\"",mName.c_str());

	}
protected:
	PolyCut(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYCUT_H__