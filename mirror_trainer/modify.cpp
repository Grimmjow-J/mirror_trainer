#include<iostream>
#include<string>





#include<windows.h>
#include<tlhelp32.h>



#include"wid.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;

void modify_gold(processinfo* pmirror) {
	wchar_t modulename[] = L"mono.dll";
	DWORD modulebaseaddress, baseaddress, temp;
	unsigned curr_gold, gold;


	modulebaseaddress = pmirror->getModuleBaseAddress(modulename);
	baseaddress = modulebaseaddress + 0x001F8BC8;
	//cout << baseaddress << endl;

	ReadProcessMemory(pmirror->hnd, (PBYTE*)baseaddress, &temp, sizeof(temp), 0);
	//cout << std::hex << temp << endl;
	//ReadProcessMemory(pmirror->hnd, (PBYTE*)temp, &temp, sizeof(temp), 0);
	ReadProcessMemory(pmirror->hnd, (PBYTE*)(temp + 0xa4), &temp, sizeof(temp), 0);
	ReadProcessMemory(pmirror->hnd, (PBYTE*)(temp + 0x4), &temp, sizeof(temp), 0);
	ReadProcessMemory(pmirror->hnd, (PBYTE*)(temp + 0xe4), &temp, sizeof(temp), 0);
	//cout << std::hex << temp << endl;
	ReadProcessMemory(pmirror->hnd, (PBYTE*)(temp + 0x30), &temp, sizeof(temp), 0);
	ReadProcessMemory(pmirror->hnd, (PBYTE*)(temp + 0x610), &temp, sizeof(temp), 0);
	ReadProcessMemory(pmirror->hnd, (PBYTE*)(temp + 0x130), &temp, sizeof(temp), 0);
	temp = temp + 0x4c;
	//cout << std::hex << temp << endl;
	//ReadProcessMemory(hnd, (PBYTE*)(temp + 8), &temp, sizeof(temp), 0);
	ReadProcessMemory(pmirror->hnd, (PBYTE*)temp, &curr_gold, sizeof(curr_gold), 0);
	cout << "��ǰ��ǮΪ��" << curr_gold << endl;
	//system("pause");
	cout << "�������޸���ֵ��" << endl;
	cin >> gold;
	cout << "�����޸�....." << endl;
	WriteProcessMemory(pmirror->hnd, (PBYTE*)temp, &gold, sizeof(gold), 0);
	cout << "�޸���ϣ���ֵ��ʱ����ı䣬���������ѣ������޸Ĳ�����Ч��" << endl;




}


void torn(processinfo* pmirror) {

	unsigned char arrayofbytes[] = { 0x83,0xC4,0x10,0x8B,0xC8,0x8B,0x45,0xDC,0x3B,0xC1,0x0F,0x8D,0xBC };
	DWORD writem1, writem2, writem3, writem4, address_m;



	address_m = pmirror->getAOB_Address(arrayofbytes);
	writem1 = 0xE9;
	writem2 = 0xBD;
	writem3 = 0x00;
	writem4 = 0x90;

	cout << "�����޸�...." << endl;

	WriteProcessMemory(pmirror->hnd, (PBYTE*)(address_m + 10), &writem1, 1, 0);
	WriteProcessMemory(pmirror->hnd, (PBYTE*)(address_m + 11), &writem2, 1, 0);
	WriteProcessMemory(pmirror->hnd, (PBYTE*)(address_m + 12), &writem3, 1, 0);
	WriteProcessMemory(pmirror->hnd, (PBYTE*)(address_m + 15), &writem4, 1, 0);
	cout << "�޸���ɣ���Ҫ�ָ�ԭ������Ϸ������������Ϸ��" << endl;

	system("pause");



}

void kill_in_one_hit(processinfo* pmirror) {

	wchar_t modulename[] = L"mono.dll";
	DWORD add, temp, i = 1;
	add = pmirror->getModuleBaseAddress(modulename);
	//cout << std::hex << add << endl;
	add = add + 0x001F4680;

	ReadProcessMemory(pmirror->hnd, (PBYTE*)add, &temp, sizeof(temp), 0);
	ReadProcessMemory(pmirror->hnd, (PBYTE*)(temp + 0x28), &temp, sizeof(temp), 0);
	ReadProcessMemory(pmirror->hnd, (PBYTE*)(temp + 0x34), &temp, sizeof(temp), 0);
	ReadProcessMemory(pmirror->hnd, (PBYTE*)(temp + 0x8), &temp, sizeof(temp), 0);
	ReadProcessMemory(pmirror->hnd, (PBYTE*)(temp + 0x5c), &temp, sizeof(temp), 0);
	ReadProcessMemory(pmirror->hnd, (PBYTE*)(temp + 0x18), &temp, sizeof(temp), 0);
	ReadProcessMemory(pmirror->hnd, (PBYTE*)(temp + 0x48), &temp, sizeof(temp), 0);
	temp = temp + 0x24;
	WriteProcessMemory(pmirror->hnd, (PBYTE*)temp, &i, sizeof(i), 0);
	cout << "�޸���ɣ��´ι�����ɱ��ֻ����Чһ�Σ���Ҫ������ɱ�����ʹ�ñ�ѡ�" << endl;
	//system("pause");
}

int main() {



	string windowname = "mirror";
	processinfo pmirror;
	//HANDLE hnd;
	int op;





	pmirror.windowname = windowname;
	pmirror.setall();





	cout << "successfully open process!" << endl;
	system("pause");
	system("cls");

	while (1) {
		cout << "�˵������ڴ���Ϸ�������������򣡣�" << endl;
		cout << "1���޸Ľ�Ǯ�������浵���ٽ����޸ģ���" << endl;
		cout << "2��һ�����£��뱣֤��ս�����沢���ٶ��������ٽ���һ�ι������ٳ��ԣ���" << endl;
		cout << "3��һ����ɱ���뱣֤��ս�����棡��һ�ι�����ɱ��ֻ����Чһ�Σ���" << endl;
		cout << "4���˳�" << endl;
		cout << "������������ע�⣡����������" << endl;
		cout << "��һ��������ʾ�����������Ų�����!" << endl;
		cout << "��һ��������ʾ�����������Ų�����!" << endl;
		cout << "��һ��������ʾ�����������Ų�����!" << endl;


		cout << "������������ֲ��س���" << endl;
		cin >> op;
		switch (op) {
		case 1: {


			modify_gold(&pmirror);

		}; break;

		case 2: {

			torn(&pmirror);
		}; break;

		case 3: {kill_in_one_hit(&pmirror); }; break;

		case 4: {exit(0); }; break;

		default:break;

		}

		system("pause");
		system("cls");




	}
	CloseHandle(pmirror.hnd);



	//cout << 1 << endl;

	return 0;
}