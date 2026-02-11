#include "Zombie.hpp"
#include <new>
// ヒープ確保
// - new で Zombie を生成
// - 名前を設定
// - ポインタを返す
Zombie *newZombie(std::string name)
{
	return (new (std::nothrow) Zombie(name));
}