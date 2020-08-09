#pragma once

#include <Vitro.h>

class MathLayer : public Vitro::Layer
{
public:
	void OnAttach() override
	{}

	void OnDetach() override
	{}

	void OnUpdate() override
	{
		Mat2Product();
		Mat3Product();
		Mat4Product();
	}

	void OnEvent(Vitro::Event& e) override
	{}

	void Mat2Product()
	{
		Vitro::Float2x2 m1(1, 2, 3, 4);
		Vitro::Float2x2 m2(16, 15, 14, 13);
		Vitro::Float2x2 result(386, 444, 502, 560);
		LogInfo(m1 * m2 == result);
	}

	void Mat3Product()
	{
		Vitro::Float3x3 m1(.1, .2, .3, .4, .5, .6, .7, .8, .9);
		Vitro::Float3x3 m2(.9, .8, .7, .6, .5, .4, .3, .2, .1);
		Vitro::Float3x3 result(.9, 1.14, 1.38, .54, .69, .84, .18, .24, .3);
		LogInfo(m1 * m2 == result);
	}

	void Mat4Product()
	{
		Vitro::Float4x4 m1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
		Vitro::Float4x4 m2(16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);
		Vitro::Float4x4 result(386, 444, 502, 560, 274, 316, 358, 400, 162, 188, 214, 240, 50, 60, 70, 80);
		LogInfo(m1 * m2 == result);
	}
};
