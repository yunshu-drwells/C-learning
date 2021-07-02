#include <stdio.h>
#include <string.h> 
int main()
{
	char a[99];
	int b;
	gets(a);
	int n=strlen(a);
	for(int i=0;i<n;i++)
	{	
		if(a[i]>='0'&&a[i]<='9'||a[i]>='a'&&a[i]<='z'||a[i]>='A'&&a[i]<='Z'||a[i]=='_')
		b=1;
	}
	if(a[0]<='9'&&a[0]>='0') b=2;
	if(b==1) printf("YES");
	else printf("NO");
}
/*C语言中的非法标识符 
     32
!    33
"    34
#    35
$    36
%    37
&    38
'    39
(    40
)    41
*    42
+    43
,    44
-    45
.    46
/    47

:    58
;    59
<    60
=    61
>    62
?    63
@    64

[    91
\    92
]    93
^    94
_    95
`    96

{    123
|    124
}    125
~    126
*/
