/*#include <iostream>
#include <cctype>
using namespace std;

void get_loweralp(char* str);
void print_alpha(char* str);

int main() {
    char str[10001];

    cout << "���� �ؽ�Ʈ�� �Է��ϼ���. ������׷��� �׸��ϴ�." << endl;
    cout << "�ؽ�Ʈ�� ���� ;�Դϴ�. 10000������ �����մϴ�." << endl;
    cin.getline(str, 10001, ';');
    get_loweralp(str);

    print_alpha(str);

    cout << "����Ϸ��� �ƹ� Ű�� �����ʽÿ�..." << endl;

    return 0;
}*/

/*�Լ� get_loweralp
  ���忡 �ִ� ���ĺ��� ������ ����, ��� �빮�ڸ� �ҹ��ڷ� �ٲ���*/
/*
void get_loweralp(char* str) {
    int cnt_al = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i]) == 1 || isalpha(str[i]) == 2) { // ���ĺ��� ���� ����
            cnt_al++;
        }
        if (isalpha(str[i]) == 1) { // �빮�ڸ� �ҹ��ڷ� �ٲپ��ֱ� 
            str[i] = tolower(str[i]);
        }
    }

    cout << "�� ���ĺ� �� " << cnt_al << endl;
    cout << endl;
}*/

/*�Լ� print_alpha
  ������ �����ϴ� ���ĺ��� �� ������ ���� *�� �����*/

/*
void print_alpha(char* str) {
    int cnt = 0;

    for (int j = 97; j <= 122; j++) { // ���ĺ� ���� ����
        for (int i = 0; i < strlen(str); i++) {
            if (j == str[i]) {
                cnt++;
            }
        }

        cout << char(j) << "(" << cnt << ")" << " : ";

        for (int k = 0; k < cnt; k++) {
            cout << "*"; // ���ĺ� ����ŭ *���            
        }

        cout << endl;
        cnt = 0;
    }

}*/



