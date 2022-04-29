#include "GameScene.h"

#include "Math/Constants.h"
#include "Rendering/EngineRenderer.h"

void rle::GameScene::onEnter()
{
	m_Cube = {
		{ { 0.0f, 0.0f, 0.0f },	{ 0.0f, 1.0f, 0.0f }, { 1.0f, 1.0f, 0.0f } },
		{ { 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 0.0f }, { 1.0f, 0.0f, 0.0f } },

		{ { 1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 0.0f }, { 1.0f, 1.0f, 1.0f } },
		{ { 1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f }, { 1.0f, 0.0f, 1.0f } },

		{ { 1.0f, 0.0f, 1.0f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 1.0f, 1.0f } },
		{ { 1.0f, 0.0f, 1.0f }, { 0.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 1.0f } },

		{ { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f, 1.0f }, { 0.0f, 1.0f, 0.0f } },
		{ { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },

		{ { 0.0f, 1.0f, 0.0f }, { 0.0f, 1.0f, 1.0f }, { 1.0f, 1.0f, 1.0f } },
		{ { 0.0f, 1.0f, 0.0f }, { 1.0f, 1.0f, 1.0f }, { 1.0f, 1.0f, 0.0f } },

		{ { 1.0f, 0.0f, 1.0f }, { 0.0f, 0.0f, 1.0f }, { 0.0f, 0.0f, 0.0f } },
		{ { 1.0f, 0.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 1.0f, 0.0f, 0.0f } }
	};

	m_CubeTransform.setPosition(0.0f, 0.0f, 3.0f);
	m_CubeTransform.setScale({ .2f, .2f, .2f });

	m_Table.load("testing_table.obj");
	m_TableTransform.setPosition(0.0f, 0.0f, 100.0f);
}

void rle::GameScene::onExit()
{

}

void rle::GameScene::update(const float delta)
{
	static float r = 0.0f;
	r += delta * 0.0002f * math::constants::PI;

	const auto tx = cos(r);
	const auto ty = sin(r);

	//m_CubeTransform.setPosition(0.0f, ty * 3.0f, 3.0f);
	m_CubeTransform.setRotation({ 0.0f, r * math::constants::PI_F, 0.0f});
}

bool rle::GameScene::draw(const EngineRenderer& renderer) const
{
	//renderer.render3D(m_Cube, m_Camera, m_CubeTransform);
	renderer.render3D(m_Table, m_Camera, m_TableTransform);

	return true;
}
