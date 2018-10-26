//
// Created by PulsarV on 18-10-26.
//
void CharToLong(char Dest[],char Source[]){
    *Dest 		= Source[3];
    *(Dest+1) 	= Source[2];
    *(Dest+2) 	= Source[1];
    *(Dest+3) 	= Source[0];
}
