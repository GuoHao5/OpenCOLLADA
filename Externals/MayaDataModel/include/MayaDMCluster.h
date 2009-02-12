/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CLUSTER_H__
#define __MayaDM_CLUSTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMWeightGeometryFilter.h"
namespace MayaDM
{
class Cluster : public WeightGeometryFilter
{
public:
	struct ClusterXforms{
		void write(FILE* file) const
		{
		}
	};
public:
	Cluster():WeightGeometryFilter(){}
	Cluster(FILE* file,const std::string& name,const std::string& parent=""):WeightGeometryFilter(file, name, parent, "cluster"){}
	virtual ~Cluster(){}
	void setPercentResolution(float ptr)
	{
		if(ptr == 5) return;
		fprintf(mFile,"\tsetAttr \".ptr\" %f;\n", ptr);

	}
	void setUsePartialResolution(unsigned int upr)
	{
		if(upr == 0) return;
		fprintf(mFile,"\tsetAttr \".upr\" %i;\n", upr);

	}
	void setRelative(bool rel)
	{
		if(rel == false) return;
		fprintf(mFile,"\tsetAttr \".rel\" %i;\n", rel);

	}
	void setWeightedCompensationMatrix(const matrix& wcm)
	{
		if(wcm == identity) return;
		fprintf(mFile,"\tsetAttr \".wcm\" -type \"matrix\" ");
		wcm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setGeomMatrix(size_t gm_i,const matrix& gm)
	{
		if(gm == identity) return;
		fprintf(mFile,"\tsetAttr \".gm[%i]\" -type \"matrix\" ",gm_i);
		gm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setGeomMatrix(size_t gm_start,size_t gm_end,matrix* gm)
	{
		fprintf(mFile,"\tsetAttr \".gm[%i:%i]\" ", gm_start,gm_end);
		size_t size = (gm_end-gm_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			gm[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");

	}
	void startGeomMatrix(size_t gm_start,size_t gm_end)
	{
		fprintf(mFile,"\tsetAttr \".gm[%i:%i]\"",gm_start,gm_end);
		fprintf(mFile," -type \"matrix\" ");

	}
	void appendGeomMatrix(const matrix& gm)
	{
		fprintf(mFile,"\n");
		gm.write(mFile);

	}
	void endGeomMatrix()
	{
		fprintf(mFile,";\n");

	}
	void setMatrix(const matrix& ma)
	{
		if(ma == identity) return;
		fprintf(mFile,"\tsetAttr \".ma\" -type \"matrix\" ");
		ma.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBindPreMatrix(const matrix& pm)
	{
		if(pm == identity) return;
		fprintf(mFile,"\tsetAttr \".pm\" -type \"matrix\" ");
		pm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setAngleInterpolation(unsigned int ait)
	{
		if(ait == 0) return;
		fprintf(mFile,"\tsetAttr \".ait\" %i;\n", ait);

	}
	void getUsePartialResolution()
	{
		fprintf(mFile,"\"%s.upr\"",mName.c_str());

	}
	void getRelative()
	{
		fprintf(mFile,"\"%s.rel\"",mName.c_str());

	}
	void getClusterXforms()
	{
		fprintf(mFile,"\"%s.x\"",mName.c_str());

	}
	void getPreMatrix()
	{
		fprintf(mFile,"\"%s.x.pre\"",mName.c_str());

	}
	void getWeightedMatrix()
	{
		fprintf(mFile,"\"%s.x.wt\"",mName.c_str());

	}
	void getPostMatrix()
	{
		fprintf(mFile,"\"%s.x.post\"",mName.c_str());

	}
	void getWeightedCompensationMatrix()
	{
		fprintf(mFile,"\"%s.wcm\"",mName.c_str());

	}
	void getGeomMatrix(size_t gm_i)
	{
		fprintf(mFile,"\"%s.gm[%i]\"",mName.c_str(),gm_i);

	}
	void getMatrix()
	{
		fprintf(mFile,"\"%s.ma\"",mName.c_str());

	}
	void getBindPreMatrix()
	{
		fprintf(mFile,"\"%s.pm\"",mName.c_str());

	}
	void getBindState()
	{
		fprintf(mFile,"\"%s.bs\"",mName.c_str());

	}
	void getPostCompensationMatrix()
	{
		fprintf(mFile,"\"%s.psc\"",mName.c_str());

	}
	void getPreCompensationMatrix()
	{
		fprintf(mFile,"\"%s.prc\"",mName.c_str());

	}
	void getAngleInterpolation()
	{
		fprintf(mFile,"\"%s.ait\"",mName.c_str());

	}
protected:
	Cluster(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:WeightGeometryFilter(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CLUSTER_H__