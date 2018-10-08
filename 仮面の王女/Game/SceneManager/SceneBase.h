//シーンベース
#pragma once

class SceneBase
{
public:
	SceneBase();
	~SceneBase();

	// 描画
	virtual bool Update() = 0;
	// 更新
	virtual void Render() = 0;
private:
};

