#include "Knight.h"
#include "cocos2d.h"
USING_NS_CC;


void Knight::SetAllAnimationFile()
{
	m_strHeroBigHeadFileName = "LFR/knight/knight_f.png";
	m_strHeroSmallHeadFileName = "LFR/knight/knight_s.png";

	m_strFacetoLeftStaticFileName = "LFR/knight/knight_0_mirror.png";
	m_strFacetoRightStaticFileName = "LFR/knight/knight_0.png";

	m_strFacetoLeftMoveFileName = "LFR/knight/knight_0_mirror.png";
	m_strFacetoRightMoveFileName = "LFR/knight/knight_0.png";

	m_strFacetoLeftAttackFileName = "LFR/knight/knight_0_mirror.png";
	m_strFacetoRightAttackFileName = "LFR/knight/knight_0.png";

	m_strFacetoLeftMagicAttackFileName;
	m_strFacetoRightMagicAttackFileName;

	m_strFacetoLeftParryFileName = "LFR/knight/knight_0_mirror.png";
	m_strFacetoRightParryFileName = "LFR/knight/knight_0.png";

	m_strFacetoLeftBeHitFileName;
	m_strFacetoRightBeHitFileName;

	m_strFacetoLeftGetUpFileName;
	m_strFacetoRightGetUpFileName;

	m_strFacetoLeftDieFileName = "LFR/knight/knight_0_mirror.png";
	m_strFacetoRightDieFileName = "LFR/knight/knight_0.png";
}

void Knight::SetFacetoLeftStaticAnimation()
{
	m_pSprite = Sprite::create(m_strFacetoLeftStaticFileName.c_str(),Rect(9 * 80,0,80,80));
	m_pSprite->setScale(2);
	this->addChild(m_pSprite,1,m_HeroID);

}

void Knight::SetFacetoRightStaticAnimation()
{

	m_pSprite = Sprite::create(m_strFacetoRightStaticFileName.c_str(),Rect(0,0,80,80));
	m_pSprite->setScale(2);
	this->addChild(m_pSprite,1,m_HeroID);
}

void Knight::SetFacetoLeftMoveAnimation()
{
	m_State = MOVE_STATE;

	DEFINE_ANIMATION_WITHOUT_CALLBACK(m_strFacetoLeftMoveFileName.c_str(),0,9,1,false,80,80,0.1,true,-2.5);
	/*cocos2d::Sequence *sequence = NULL;
	cocos2d::Spawn *spawn = NULL;

	Animation *attack;
	Texture2D *pic = 0;
	Vector<SpriteFrame*> arr;

	pic = TextureCache::getInstance()->addImage(m_strFacetoLeftMoveFileName.c_str());

	for (int i = 9; i >= 2; --i)
	{
		int index = 0;
		SpriteFrame* sf = SpriteFrame::createWithTexture(pic,Rect(i * 80,index * 80,80,80));
		arr.pushBack(sf);
	}

	attack = Animation::createWithSpriteFrames(arr,0.1f);

	auto action = Animate::create(attack);
	auto Repeat_left = Repeat::create(action,-2.5);	
	m_pSequence = Sequence::create(action,Repeat_left,NULL);
	m_pSprite->runAction(m_pSequence);*/
}

void Knight::SetFacetoRightMoveAnimation()
{
	m_State = MOVE_STATE;

	DEFINE_ANIMATION_WITHOUT_CALLBACK(m_strFacetoRightStaticFileName.c_str(),0,0,8,true,80,80,0.1,true,-2.5);
}

void Knight::SetFacetoLeftAttackAnimation()
{
	m_State = ATTACK_STATE;

	DEFINE_ANIMATION_WITH_CALLBACK(m_strFacetoLeftAttackFileName.c_str(),1,9,3,false,80,80,0.1,false,0,Hero::AttackEnd);
}

void Knight::SetFacetoRightAttackAnimation()
{
	m_State = ATTACK_STATE;

	DEFINE_ANIMATION_WITH_CALLBACK(m_strFacetoRightAttackFileName.c_str(),1,0,6,true,80,80,0.1,false,0,Hero::AttackEnd);
}

void Knight::SetFacetoLeftMagicAttackAnimation(cocos2d::Sequence*& seq)
{
	m_State = MAGICATTACK_STATE;
	DEFINE_MOVE_MAGIC(seq,"LFR/freeze/freeze_ball_mirror.png",directon_left,GlobalValue::magic_distance,0,2,3,-1,false,82,83,0.1);

	
}

void Knight::SetFacetoRightMagicAttackAnimation(cocos2d::Sequence*& seq)
{
	m_State = MAGICATTACK_STATE;
	DEFINE_MOVE_MAGIC(seq,"LFR/freeze/freeze_ball.png",directon_right,GlobalValue::magic_distance,0,2,3,-1,false,82,83,0.1);
}

void Knight::SetFacetoLeftParryAnimation()
{

	/*cocos2d::Sequence *sequence = NULL;
	cocos2d::Spawn *spawn = NULL;

	Animation *attack;
	Texture2D *pic = 0;
	Vector<SpriteFrame*> arr;

	pic = TextureCache::getInstance()->addImage(m_strFacetoLeftParryFileName.c_str());

	for (int i = 5; i >= 2; --i)
	{
		int index = 1;
		SpriteFrame* sf = SpriteFrame::createWithTexture(pic,Rect(i * 80,index * 80,80,80));
		arr.pushBack(sf);
	}


	attack = Animation::createWithSpriteFrames(arr,0.5f);

	auto action = Animate::create(attack);

	m_pSequence = Sequence::create(action,CallFunc::create(CC_CALLBACK_0(Hero::AttackEnd,this)),NULL);
	m_pSprite->runAction(m_pSequence);*/
	DEFINE_ANIMATION_WITH_CALLBACK(m_strFacetoLeftParryFileName.c_str(),1,3,-1,false,80,80,0.5,true,3,Hero::AttackEnd);
}


void Knight::SetFacetoRightParryAnimation()
{
	/*cocos2d::Sequence *sequence = NULL;
	cocos2d::Spawn *spawn = NULL;

	Animation *attack;
	Texture2D *pic = 0;
	Vector<SpriteFrame*> arr;

	pic = TextureCache::getInstance()->addImage(m_strFacetoRightParryFileName.c_str());

	for (int i = 5; i < 8; ++i)
	{
		int index = 1;
		SpriteFrame* sf = SpriteFrame::createWithTexture(pic,Rect(i * 80,index * 80,80,80));
		arr.pushBack(sf);
	}


	attack = Animation::createWithSpriteFrames(arr,0.5f);

	auto action = Animate::create(attack);

	m_pSequence = Sequence::create(action,CallFunc::create(CC_CALLBACK_0(Hero::AttackEnd,this)),NULL);
	m_pSprite->runAction(m_pSequence);*/

	DEFINE_ANIMATION_WITH_CALLBACK(m_strFacetoRightParryFileName.c_str(),3,6,10,true,80,80,0.5,true,3,Hero::AttackEnd);
}

void Knight::SetFacetoLeftInjuredAnimation()
{
}

void Knight::SetFacetoRightInjuredAnimation()
{
}

void Knight::SetFacetoLeftBeHitAnimation()
{
}

void Knight::SetFacetoRightBeHitAnimation()
{
}

void Knight::SetFacetoLeftGetUpAnimation()
{
}

void Knight::SetFacetoRightGetUpAnimation()
{
}

void Knight::SetFacetoLeftDieAnimation()
{
	m_State = DEATH_STATE;

	DEFINE_ANIMATION_WITHOUT_CALLBACK(m_strFacetoLeftDieFileName.c_str(),3,8,4,false,80,80,0.2,false,0);
}

void Knight::SetFacetoRightDieAnimation()
{
	m_State = DEATH_STATE;

	DEFINE_ANIMATION_WITHOUT_CALLBACK(m_strFacetoRightDieFileName.c_str(),3,1,5,true,80,80,0.2,false,0);

}