/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LIGHTLINKER_H__
#define __MayaDM_LIGHTLINKER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class LightLinker : public DependNode
{
public:
	struct Link{
		void write(FILE* file) const
		{
		}
	};
	struct Ignore{
		void write(FILE* file) const
		{
		}
	};
	struct ShadowLink{
		void write(FILE* file) const
		{
		}
	};
	struct ShadowIgnore{
		void write(FILE* file) const
		{
		}
	};
public:
	LightLinker():DependNode(){}
	LightLinker(FILE* file,const std::string& name,const std::string& parent="",bool create=true)
		:DependNode(file, name, parent, "lightLinker", create){}
	virtual ~LightLinker(){}
	void setLink(size_t lnk_i,const Link& lnk)
	{
		fprintf(mFile,"\tsetAttr \".lnk[%i]\" ",lnk_i);
		lnk.write(mFile);
		fprintf(mFile,";\n");

	}
	void setIgnore(size_t ign_i,const Ignore& ign)
	{
		fprintf(mFile,"\tsetAttr \".ign[%i]\" ",ign_i);
		ign.write(mFile);
		fprintf(mFile,";\n");

	}
	void setShadowLink(size_t slnk_i,const ShadowLink& slnk)
	{
		fprintf(mFile,"\tsetAttr \".slnk[%i]\" ",slnk_i);
		slnk.write(mFile);
		fprintf(mFile,";\n");

	}
	void setShadowIgnore(size_t sign_i,const ShadowIgnore& sign)
	{
		fprintf(mFile,"\tsetAttr \".sign[%i]\" ",sign_i);
		sign.write(mFile);
		fprintf(mFile,";\n");

	}
	void getLink(size_t lnk_i)const
	{
		fprintf(mFile,"\"%s.lnk[%i]\"",mName.c_str(),lnk_i);

	}
	void getLink()const
	{

		fprintf(mFile,"\"%s.lnk\"",mName.c_str());

	}
	void getLight(size_t lnk_i)const
	{
		fprintf(mFile,"\"%s.lnk[%i].llnk\"",mName.c_str(),lnk_i);

	}
	void getLight()const
	{

		fprintf(mFile,"\"%s.lnk.llnk\"",mName.c_str());

	}
	void getObject(size_t lnk_i)const
	{
		fprintf(mFile,"\"%s.lnk[%i].olnk\"",mName.c_str(),lnk_i);

	}
	void getObject()const
	{

		fprintf(mFile,"\"%s.lnk.olnk\"",mName.c_str());

	}
	void getIgnore(size_t ign_i)const
	{
		fprintf(mFile,"\"%s.ign[%i]\"",mName.c_str(),ign_i);

	}
	void getIgnore()const
	{

		fprintf(mFile,"\"%s.ign\"",mName.c_str());

	}
	void getLightIgnored(size_t ign_i)const
	{
		fprintf(mFile,"\"%s.ign[%i].lign\"",mName.c_str(),ign_i);

	}
	void getLightIgnored()const
	{

		fprintf(mFile,"\"%s.ign.lign\"",mName.c_str());

	}
	void getObjectIgnored(size_t ign_i)const
	{
		fprintf(mFile,"\"%s.ign[%i].oign\"",mName.c_str(),ign_i);

	}
	void getObjectIgnored()const
	{

		fprintf(mFile,"\"%s.ign.oign\"",mName.c_str());

	}
	void getShadowLink(size_t slnk_i)const
	{
		fprintf(mFile,"\"%s.slnk[%i]\"",mName.c_str(),slnk_i);

	}
	void getShadowLink()const
	{

		fprintf(mFile,"\"%s.slnk\"",mName.c_str());

	}
	void getShadowLight(size_t slnk_i)const
	{
		fprintf(mFile,"\"%s.slnk[%i].sllk\"",mName.c_str(),slnk_i);

	}
	void getShadowLight()const
	{

		fprintf(mFile,"\"%s.slnk.sllk\"",mName.c_str());

	}
	void getShadowObject(size_t slnk_i)const
	{
		fprintf(mFile,"\"%s.slnk[%i].solk\"",mName.c_str(),slnk_i);

	}
	void getShadowObject()const
	{

		fprintf(mFile,"\"%s.slnk.solk\"",mName.c_str());

	}
	void getShadowIgnore(size_t sign_i)const
	{
		fprintf(mFile,"\"%s.sign[%i]\"",mName.c_str(),sign_i);

	}
	void getShadowIgnore()const
	{

		fprintf(mFile,"\"%s.sign\"",mName.c_str());

	}
	void getShadowLightIgnored(size_t sign_i)const
	{
		fprintf(mFile,"\"%s.sign[%i].slig\"",mName.c_str(),sign_i);

	}
	void getShadowLightIgnored()const
	{

		fprintf(mFile,"\"%s.sign.slig\"",mName.c_str());

	}
	void getShadowObjectIgnored(size_t sign_i)const
	{
		fprintf(mFile,"\"%s.sign[%i].soig\"",mName.c_str(),sign_i);

	}
	void getShadowObjectIgnored()const
	{

		fprintf(mFile,"\"%s.sign.soig\"",mName.c_str());

	}
protected:
	LightLinker(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool create=true)
		:DependNode(file, name, parent, nodeType, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_LIGHTLINKER_H__