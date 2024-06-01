#pragma once
#include"Singleton.h"
#include"Global.h"

class Collider;

union COLLIDER_ID {
    struct {
        UINT left_Id;
        UINT right_Id;
    };
    LONGLONG ID;
};

class ColliderManager :
    public Singleton<ColliderManager>
{
private:
    UINT m_arrCheck[(UINT)GROUP_TYPE::END];
    map<LONGLONG, bool> m_mapColInfo; //충돌체간 이전 프레임 정보

    void Collied(GROUP_TYPE left, GROUP_TYPE right);
    bool IsCollision(Collider* left, Collider* right);
public:
    void Init();
    void CheckGroup(GROUP_TYPE left, GROUP_TYPE right);
    void Update();
    void Reset();
};

