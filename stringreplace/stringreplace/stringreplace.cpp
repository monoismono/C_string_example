// stringreplace.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"


int replce_str(char* pchrsource,char* pchrfind,char* pchrrep)
{
char pchrresult[1000];//
char* pchrformer;
char* pchrlocation;
int intrep;// ������r������
int intfind;// �j�M��r������
int intlength;// ���G��r������
int intgap=0;// �����q

intfind=strlen(pchrfind);// �j�M��r������
intrep=strlen(pchrrep);// ������r������
intlength=strlen(pchrsource)+1;// ���G��r������

//pchrresult = (char*)malloc(sizeof(char) * intlength);// �t�m�O����
strcpy_s(pchrresult, pchrsource);//�ƻs��r

pchrformer=pchrsource;
pchrlocation= strstr(pchrformer, pchrfind);//�j�M��r�X�{���_�l��}����

while(pchrlocation!=NULL){

intgap+=(pchrlocation - pchrformer);//�w�찾���q
pchrresult[intgap]='\0';// �N�����Ÿ��w�b�j�M�쪺��}�W

intlength+=(intrep-intfind);//�p��s������
//pchrresult = (char*)realloc(pchrresult, intlength * sizeof(char));// �ܧ�O����Ŷ�
strcat_s(pchrresult, pchrrep);//�걵�b���G�᭱
intgap+=intrep;//��s�����q


pchrformer=pchrlocation+intfind;//��s�|���Q���N���r�ꪺ��}

strcat_s(pchrresult, pchrformer);//�N�|���Q���N����r�걵�b���G�᭱


pchrlocation= strstr(pchrformer, pchrfind);//�j�M��r�X�{���_�l��}����
}

pchrresult[strlen(pchrresult)]='\0';

strcpy(pchrsource,pchrresult);
//free(pchrresult);
return 0;
}


int main(){
char pchrsource[5000];
char* pchrfind="5";
char* pchrrep="abcd";
strcpy_s(pchrsource, "123456789");
printf( "source: '%s'\n", pchrsource );
replce_str(pchrsource,pchrfind,pchrrep);
printf( "source: '%s'\n", pchrsource );

system("PAUSE");
return 0;
}

