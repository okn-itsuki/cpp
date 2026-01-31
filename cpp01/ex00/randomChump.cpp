#include "Zombie.hpp"

// スタック確保
// - ローカル変数として Zombie を生成
// - announce() を呼ぶ
// - 関数終了時に 自動で破棄
void randomChump(std::string name)
{
	Zombie zombie = Zombie(name);
	zombie.announce();
}