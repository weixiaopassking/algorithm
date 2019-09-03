#ifndef SINGLETON_H
#define SINGLETON_H
#include <bits/stdc++.h>
using namespace std;

// 懒汉式单例模式
class Singleton
{
public:
    static Singleton* GetInstance(){
        if(nullptr==m_pSingleton){
            m_pSingleton = new Singleton();
        }
        return m_pSingleton;
    }

private:
    Singleton() {
        cout<<"Lazy Singleton:"<<
              (m_pSingleton==nullptr? " m_pSingleton=nullptr":"m_pSingleton!=nullptr")<<endl;
    }

private:
    static Singleton *m_pSingleton;  // 指向单例对象的指针
};

Singleton* Singleton::m_pSingleton=nullptr;

int main(){
    Singleton* s=nullptr;
    s = Singleton::GetInstance();
    return 0;
}
#endif



/////////////////////////分界线：下面是饿汉式单例模式/////////////////////////
#ifndef SINGLETON_H
#define SINGLETON_H
#include <bits/stdc++.h>
using namespace std;

// 饿汉式单例模式
class Singleton
{
public:
    // 单例 - 饿汉式
    static Singleton* GetInstance(){
        cout<<"Hungry singleton GetInstance ok!"<<endl;;
        return m_pSingleton;
    }

private:
    Singleton() {
        cout<<"Hungry Singleton:"<<
              (m_pSingleton==nullptr? "m_pSingleto=nullptr":"m_pSingleton!=nullptr")<<endl;
    }

private:
    // 指向单例对象的指针
    static Singleton *m_pSingleton;
};

Singleton* Singleton::m_pSingleton = new Singleton();

int main(){
    Singleton* s=nullptr;
    s = Singleton::GetInstance();
    return 0;
}
#endif


/////////////////////////分界线：下面是多线程安全懒汉单例模式/////////////////////////
#ifndef SINGLETON_H
#define SINGLETON_H
#include <bits/stdc++.h>
#include <mutex>
using namespace std;

// 懒汉式单例模式
class Singleton
{
private:
    static Singleton* m_pSingleton;  // 指向单例对象的指针
    static mutex mt;
    Singleton() {
        cout<<"Thread safe Singleton:"<<
              (m_pSingleton==nullptr? "m_pSingleton=nullptr" : "m_pSingleton!=nullptr")<<endl;
    }

public:
    static Singleton* GetInstance(){
        if(nullptr == m_pSingleton){
            mt.lock();
            if(nullptr == m_pSingleton){
                m_pSingleton = new Singleton();
            }
            mt.unlock();
        }
        return m_pSingleton;
    }
};

mutex Singleton::mt;
Singleton* Singleton::m_pSingleton;

int main(){
    Singleton* s=nullptr;
    s = Singleton::GetInstance();
    return 0;
}

#endif



