#include <stdio.h>
#include <stdlib.h>


char * letters[68];

void filltheTable(char *letters [68]){
	
	int i=0;
	
	/*kefalaia grammata */

	/*193-209 */
	letters[i++]="A";	/* 193 */
	letters[i++]="V";	/* 194 */
	letters[i++]="G";	/* 195 */
	letters[i++]="D";	/* 196 */
	letters[i++]="E";	/* 197 */
	letters[i++]="Z";	/* 198 */
	letters[i++]="H";	/* 199 */
	letters[i++]="8";	/* 200 */
	letters[i++]="I";	/* 201 */
	letters[i++]="K";	/* 202 */
	letters[i++]="L";	/* 203 */
	letters[i++]="M";	/*204 katastasi allazei B */
	letters[i++]="N";	/*205 katastasi allazei D */
	letters[i++]="Ks";	/* 206 */
	letters[i++]="O";	/* 207 */
	letters[i++]="P";	/* 208 */
	letters[i++]="R";	/* 209 */
	letters[i++]="S";	/* 211 */
	letters[i++]="T";	/* 212 */
	letters[i++]="Y";	/* 213 */
	letters[i++]="F";	/* 214 */
	letters[i++]="X";	/* 215 */
	letters[i++]="Ps";	/* 216 */
	letters[i++]="W";	/* 217  */

	/* mikra grammata  */

	/*225-249 */
	letters[i++]="a";	/* 225 */
	letters[i++]="v";	/* 226 */
	letters[i++]="g";	/* 227 */
	letters[i++]="d";	/* 228 */
	letters[i++]="e";	/* 229 */
	letters[i++]="z";	/* 230 */
	letters[i++]="h";	/* 231 */
	letters[i++]="8";	/* 232 */
	letters[i++]="i";	/* 233 */
	letters[i++]="k";	/* 234 */
	letters[i++]="l";	/* 235 */
	letters[i++]="m";	/* 236 katastasi allazei se b */
	letters[i++]="n";	/* 237 katastasi allazei se d */
	letters[i++]="ks";	/* 238 */
	letters[i++]="o";	/* 239 */
	letters[i++]="p";	/* 240 */
	letters[i++]="r";	/* 241 */
	letters[i++]="s";	/*242 sigma teliko */
	letters[i++]="s";	/*243 sigma mikro  */

	letters[i++]="t";	/* 244 */
	letters[i++]="y";	/* 245 */
	letters[i++]="f";	/* 246 */
	letters[i++]="x";	/* 247 */
	letters[i++]="ps";	/* 248 */
	letters[i++]="w";	/* 249 */

	/* 	182 = "A'"
	 *	184 = "E'"
	 * 	185 = "H'"
	 * 	186 = "I'"
	 * 	188 = "O'"
	 * 	190 = "Y'"
	 * 	191 = "W'"
	 */
	
	letters[i++]="'A";	/*index=49*/
	letters[i++]="'E";	/*index=50*/
	letters[i++]="'H";	/*index=51*/
	letters[i++]="'I";	/*index=52*/
	letters[i++]="'O";	/*index=53*/
	letters[i++]="'W";	/*index=54*/
	letters[i++]="'Y";	/*index=55*/

	/*	220= "a'"
	 *	221= "e'"
	 *	222= "h'"
	 *	223= "i'"
	 *	252= "o'"
	 *	253= "y'"
	 *	254= "w'"
	 */

	letters[i++]="a'";	/*index=56*/
	letters[i++]="e'";	/*index=57*/
	letters[i++]="h'";	/*index=58*/
	letters[i++]="i'";	/*index=59*/
	letters[i++]="o'";	/*index=60*/
	letters[i++]="w'";	/*index=61*/
	letters[i++]="y'";	/*index=62*/

	/*	250 = "i\""
	 *	251 = "y\""
	 *	192 = "i'\""
	 *	224 = "y'\""
	 */

	letters[i++]="i\"";	/*index=63*/
	letters[i++]="y\"";	/*index=64*/
	letters[i++]="i'\"";	/*index=65*/
	letters[i++]="y'\"";	/*index=66*/
	
	letters[i++]=" ";	/*index=67*/

}

int MatchTheChar(int i){
	/* ta kefalaia prwta 193-217 xwris to 210  */
	/* akolouthoun ta mikra 225-249 */

	if(i>=193 && i<=209){
		return i-193;	/* 210 den antistoixei se kapoio gramma sto iso  */
	}else if(i>=211 && i<=217){
		return i-194;
	}else if(i>=225 && i<=249){
		return i-201;
	}else if(i>=220 && i<=223){	/*ta prwta 4 mikra tonismena */
		return i-164;
	}else{
		if(i==182){
			return 49;	/*index =49-55 tonoi kefalaiwn */
		}else if(i==184){
			return 50;
		}else if(i==185){
			return 51;
		}else if(i==186){
			return 52;
		}else if(i==188){
			return 53;
		}else if(i==191){
			return 54;
		}else if(i==190){
			return 55;
		}else if(i==252){	/*index=60-62 ypoloipa mikra tonismena */
			return 60;
		}else if(i==254){
			return 61;
		}else if(i==253){
			return 62;
		}else if(i==250){	/*index=63-66 dialitika me kai xwris tono  */	
			return 63;
		}else if(i==251){
			return 64;
		}else if(i==192){
			return 65;
		}else if(i==224){
			return 66;
		}else if(i==32){
			return 67;
		}else{
			return 100; /* den mas noiazoun oi allages */
		}
	}
	return 0;
}





int main(){	

	enum State {dontcare,b,d,B,D};
	enum State state = dontcare;

	unsigned char c,temp;
	/*char *isprinted;*/

	
	filltheTable(letters);
	

	while((c=getchar())!=EOF ){
		char *isprinted;

		if(c<32) continue;/*Something gone wrong */

		temp=MatchTheChar(c);
		/*printf("%s" ,letters[temp]);*/
		if(temp!=100){
		       	isprinted=letters[temp];
	     	}
		
			
		switch(state){
			case B:
				if(c==240 || c==208) isprinted="B";
				else putchar('M');
				break;
			case b:
				if(c==240 || c==208) isprinted="b";
				else putchar('m');
				break;
			case d:
				if(c==244 || c==212) isprinted="d";
				else putchar('n');
				break;
			case D:
				if(c==244 || c==212) isprinted="D";
				else putchar('N');
				break;
			default:
				break;
		}
	
		state=dontcare;

		switch(c){
			case 204: state=B;
				continue;
			case 205: state=D;
				continue;
			case 236: state=b;
				  continue;
			case 237: state=d;
				  continue;
	
		}
		while(*isprinted){
			
			putchar(*isprinted);
			isprinted++;
		}
	
	}
		
	
	return 0;
}

