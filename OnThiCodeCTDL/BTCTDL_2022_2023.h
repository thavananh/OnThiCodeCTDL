#include <iostream>
#include <string>
using namespace std;

class HocPhan;

class SV
{
    HocPhan* _pNext;
public:
    SV(HocPhan* pNext = NULL)
    {
        _pNext = pNext;
    }
    void setpNext(HocPhan* pNext)
    {
        _pNext = pNext;
    }
    HocPhan* getpNext()
    {
        return _pNext;
    }
};

class HocPhan
{
    string _strMaHP;
    string _strTenHP;
    int _iSoTC;
    bool _bBatBuoc;
    string _strMaHPTruoc;
    SV* _pNext;
public:
    HocPhan(string strMaHP = "", string strTenHP = "", int iSoTC = 0, bool bBatBuoc = false, string strMaHPTruoc = "", SV* pNext = new SV())
    {
        _strMaHP = strMaHP;
        _strTenHP = strTenHP;
        _iSoTC = iSoTC;
        _bBatBuoc = bBatBuoc;
        _strMaHPTruoc = strMaHPTruoc;
        _pNext = pNext;
    }
    HocPhan(const HocPhan& hp)
    {
        _strMaHP = hp._strMaHP;
        _strTenHP = hp._strTenHP;
        _iSoTC = hp._iSoTC;
        _bBatBuoc = hp._bBatBuoc;
        _strMaHPTruoc = hp._strMaHPTruoc;
        _pNext = hp._pNext;
    }
    void input()
    {
        cin >> _strMaHP;
        cin.ignore();
        getline(cin, _strTenHP);
        cin >> _iSoTC >> _bBatBuoc >> _strMaHPTruoc;
        _pNext = new SV();
    }
    void setNextNode(HocPhan* nextNode)
    {
        _pNext->setpNext(nextNode);
    }
    HocPhan* getpNext()
    {
        return _pNext->getpNext();
    }
    void output()
    {
        cout << "Ma hp: " << _strMaHP << endl;
        cout << "Ten hp: " << _strTenHP << endl;
        cout << "So tin chi: " << _iSoTC << endl;
        cout << "Bat buoc: " << _bBatBuoc << endl;
        cout << "Ma HP truoc: " << _strMaHPTruoc;
    } 
};



class List
{
    HocPhan* _pHead;
    HocPhan* _pTail;
public:
    List()
    {
        _pHead = _pTail = NULL;
    }
    void addHP(const HocPhan& hp)
    {
        HocPhan* node = new HocPhan(hp);
        if (_pHead == NULL)
        {
            _pHead = _pTail = node;
        }
        else
        {
            _pTail->setNextNode(node);
        }
    }
    void input()
    {
        cout << "Nhap so luong hp: "; int n; cin >> n;
        for (size_t i = 0; i < n; i++)
        {
            HocPhan hp;
            hp.input();
            addHP(hp);
        }
        
    }
    void output()
    {
        HocPhan* pWalker = _pHead;
        while (pWalker != NULL)
        {
            pWalker->output();
            pWalker = pWalker->getpNext();
        }
    }
};