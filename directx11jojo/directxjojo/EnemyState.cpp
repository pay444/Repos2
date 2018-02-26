#include "stdafx.h"
#include "EnemyState.h"

void IdleState::Enter()
{
	OutputDebugString(L"Enter Idle\n");
}

void IdleState::Execute(float dt)
{
	//�÷��̾�, ������
	Player *pPlayer = GunGeon::Blackboard::Instance().GetPlayer();
	Enemy *pEnemy = (Enemy*)(this->mpFSM->GetOwner());

	if (pPlayer == NULL || pEnemy == NULL)
		return;

	//Ž���ؼ� �������� �÷��̾� �߰��ϸ� ��������
	//Ž�� (�÷��̾� <-> �� �Ÿ�)
	float dist = Vector2::Distance(pPlayer->GetPosition(), pEnemy->GetPosition());

	//���� ���� �÷��̾� �߰�
	//if (dist < pEnemy->GetDetectRange())
	//{
	//	//���� ����
	//	mpFSM->ChangeState(GunGeon::EnemyState::Enemy_Chase);
	//}

	
}

void IdleState::Exit()
{
	OutputDebugString(L"-----------Exit Idle\n");
}

void ChaseState::Enter()
{
	OutputDebugString(L"Enter Chase\n");
}

void ChaseState::Execute(float dt)
{
	//�÷��̾�, ������
	Player *pPlayer = GunGeon::Blackboard::Instance().GetPlayer();
	Enemy *pEnemy = (Enemy*)(this->mpFSM->GetOwner());

	if (pPlayer == NULL || pEnemy == NULL)
		return;
	//�Ÿ�//Ž��
	float dist = Vector2::Distance(pEnemy->GetPosition(), pPlayer->GetPosition());
	//// �����Ÿ� �ȿ� ���ƿ��� -> Atack
	//if (dist < pEnemy->GetAttackRange())
	//{
	//	mpFSM->ChangeState(GunGeon::EnemyState::Enemy_Attack);
	//	return;
	//}
	//// Ÿ�� ��ħ -> Idle
	//if (dist > pEnemy->GetDetectRange())
	//{
	//	mpFSM->ChangeState(GunGeon::EnemyState::Enemy_Idle);
	//}
	////���� ( Ÿ�� �������� �̵�)
	//Vector2 dir = pPlayer->GetPosition() - pEnemy->GetPosition();
	//dir.Normalize();

	//pEnemy->SetPosition(pEnemy->GetPosition()+dir*pEnemy->GetSpeed() * dt);
}

void ChaseState::Exit()
{
	OutputDebugString(L"------------Exit Chase\n");
}

void AttackState::Enter()
{
	OutputDebugString(L"Enter Attack\n");
}

void AttackState::Execute(float dt)
{
	Enemy* pOwner = (Enemy*)(this->mpFSM->GetOwner());
	Player* pPlayer = GunGeon::Blackboard::Instance().GetPlayer();

	mfElapsedTime += dt;

	//if (mfElapsedTime > pOwner->GetAttackDelay())
	//{
	//	pOwner->SetTarget(pPlayer);
	//	pOwner->Fire();
	//	
	//	mfElapsedTime = 0.0f;
	//}

	
	mpFSM->ChangeState(GunGeon::EnemyState::Enemy_Chase);
}

void AttackState::Exit()
{
	OutputDebugString(L"------------Exit Attack\n");
}
