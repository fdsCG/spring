/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#ifndef STATICMOVETYPE_H
#define STATICMOVETYPE_H

#include "MoveType.h"

class CStaticMoveType : public AMoveType
{
	CR_DECLARE(CStaticMoveType)

public:
	CStaticMoveType(CUnit* unit);

	void StartMoving(float3 pos, float goalRadius) override {}
	void StartMoving(float3 pos, float goalRadius, float speed) override {}
	void StopMoving(bool callScript = false, bool hardStop = false, bool cancelRaw = false) override {}

	void SetMaxSpeed(float speed) override { /* override AMoveType (our maxSpeed IS allowed to be 0) */ }
	void KeepPointingTo(float3 pos, float distance, bool aggressive) override {}

	bool Update() override { return false; }
	void SlowUpdate() override;

	bool FloatOnWater() const override { return floatOnWater; }
	float Waterline() const override { return waterline; }

	void InitMemberData();
	bool SetMemberValue(unsigned int memberHash, void* memberValue) override;

private:
	std::array<std::pair<unsigned int,  bool*>, 1>  boolMemberData;
	std::array<std::pair<unsigned int, float*>, 1> floatMemberData;

private:
	bool floatOnWater;
	float waterline;
};

#endif // STATICMOVETYPE_H
