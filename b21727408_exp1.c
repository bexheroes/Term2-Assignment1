
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ltrim(char *str, const char *seps)
{
    size_t totrim;
    if (seps == NULL) {
        seps = "\t\n\v\f\r ";
    }
    totrim = strspn(str, seps);
    if (totrim > 0) {
        size_t len = strlen(str);
        if (totrim == len) {
            str[0] = '\0';
        }
        else {
            memmove(str, str + totrim, len + 1 - totrim);
        }
    }
    return str;
}

char *rtrim(char *str, const char *seps)
{
    int i;
    if (seps == NULL) {
        seps = "\t\n\v\f\r ";
    }
    i = strlen(str) - 1;
    while (i >= 0 && strchr(seps, str[i]) != NULL) {
        str[i] = '\0';
        i--;
    }
    return str;
}

char *trim(char *str, const char *seps)
{
    return ltrim(rtrim(str, seps), seps);
}

void printFile(char commands[],char data[]){
	FILE *myfile;
	if ( ( myfile = fopen("output.txt","a")) != NULL){
		fprintf(myfile,commands,data);
	}
	fclose(myfile);
}
void printFile2(char commands[],int i,char data[]){
	FILE *myfile;
	if ( ( myfile = fopen("output.txt","a")) != NULL){
		fprintf(myfile,commands,i,data);
	}
	fclose(myfile);
}
void printFile3(char commands[],int i,char data[],char data2[]){
	FILE *myfile;
	if ( ( myfile = fopen("output.txt","a")) != NULL){
		fprintf(myfile,commands,i,data,data2);
	}
	fclose(myfile);
}
void printFile4(char commands[],char data[],char data2[],int i){
	FILE *myfile;
	if ( ( myfile = fopen("output.txt","a")) != NULL){
		fprintf(myfile,commands,data,data2,i);
	}
	fclose(myfile);
}
void printFile5(char commands[],char data[],int i){
	FILE *myfile;
	if ( ( myfile = fopen("output.txt","a")) != NULL){
		fprintf(myfile,commands,data,i);
	}
	fclose(myfile);
}

int getSize(char get[]){
	int ct = 0,x;
	for(x=0;x<255;x++){
		if(get[x]=='\0'){
			break;
		}else{
			ct++;
		}
	}
	return ct;
}

int getSize2(char get[]){
	int ct = 0,x;
	for(x=0;x<255;x++){
		if(get[x]=='\0'){
			break;
		}else{
			ct++;
		}
	}
	ct--;
	return ct;
}

int fix(char *get){
	char foo[255];
	int ct = 0 , how = 0;
	strcpy(foo,get);
	for(ct = 0;ct<255;ct++){
		if(foo[ct]=='\0'){
			break;
		}else{
			how++;
		}
	}
	return how;
}

char *change(char sentence[],char old[],char neu[]){
	int a,b,c,d,e,f,sentence_len=0,old_len=0,neu_len=0,found=0,more=0,return_len=0;
	char keep[2];
	char *toReturn;
	
	for(a=0;a<255;a++){
		if(sentence[a]=='\0'){
			sentence_len = a;
			break;
		}
	}
	
	for(a=0;a<20;a++){
		if(old[a]=='\0'){
			old_len = a;
			break;
		}
	}
	for(a=0;a<20;a++){
		if(neu[a]=='\0'){
			neu_len = a;
			break;
		}
	}
	
	
	char mysentence[sentence_len];
	char myold[old_len];
	char myneu[neu_len];
	strncpy(mysentence,sentence,sentence_len+1);
	strncpy(myold,old,old_len+1);
	strncpy(myneu,neu,neu_len+1);
	char neusentence[255];
	strcpy(neusentence,"");

	for(a=0;a<sentence_len;a++){
		if(sentence[a]==myold[0]){
			for(b=0;b<old_len;b++){
				if(sentence[a+b]==old[b]){
					found++;
				}
			}
			if(found==old_len){
			    
				strcat(neusentence,myneu);
				a+=old_len-1;
			}else{
			keep[0]=mysentence[a];
			keep[1]='\0';
			strcat(neusentence,keep);
		}
			found=0;
		}else{
			keep[0]=mysentence[a];
			keep[1]='\0';
			strcat(neusentence,keep);
		}
	}
	
	for(a=0;a<255;a++){
		if(neusentence[a]=='\0'){
			return_len = a;
			break;
		}
	}
	return_len++;
	
	toReturn = malloc(sizeof(char)*return_len);
	strcpy(toReturn,neusentence);
	return toReturn;
		
}

int search(char sentence[],char key[]){
	char *mysentence,*mykey;
	int i=0,j=0,key_len=0,sentence_len=0,found=0,found2=0;
	for(i=0;i<255;i++){
		if(sentence[i]=='\0'){
			sentence_len = i;
			break;
		}
	}
	for(i=0;i<20;i++){
		if(key[i]=='\0'){
			key_len = i;
			break;
		}
	}
	mysentence = malloc(sizeof(char)*sentence_len);
	mykey = malloc(sizeof(char)*key_len);
	
	strcpy(mysentence,sentence);
	strcpy(mykey,key);
	

	
	for(i=0;i<sentence_len;i++){
		if(sentence_len-i < key_len){
			break;
		}
		if(*(mysentence+i)==*(mykey)){
		    
			for(j=0;j<key_len;j++){
				if(*(mysentence+i+j) == *(mykey+j)){
					found2++;
				}
			}
			if(found2==key_len){
				found++;
			}
			found2=0;
		}
	}
	
	return found;
	
}

void doIt(char filename[]){
	FILE *myfile;
	char LINE[255];
	char get_char;
	int i = 0, k = 0 , j = 0 , m , l , a ,b ,f , cc = 0 , key , p , kp = 0 , km = 0 , f_keep = 0;
	char WORDS[10][40];
	char *splt,*pth,*psh,*ksf,*aff;
	char gett;
	char something[] = "\n";
	int t=0,n=0,qq=0,sayd=0,there=0,mm=0;
	char name[20],holdd[50];
	char data[255],newdata[255],nextdata[255];
	char oldword[20],newword[20],n_hold[20],o_hold[20];
	char *db[100][2];
	char keep[50];
	int delete_i,remove_n,remove_s,remove_l,append_t = 0,append_n = 0,special,empty=0;
	int replace_n,replace_ow,replace_nw,print_t,print_cw,print_cs,print_cw_data,print_cs_data;
	int start,length,end,ct=0,ct2=1,count_words=0,count_sentences=0,howmany,ok=0;
	char extension[20],holdx[20],cmp1[20],cmp2[20];
	char *part1,*part2,*cmp;
	char *neudata;
	
	for(a=0;a<100;a++){
		db[a][0] = malloc(sizeof(char)*20);
		db[a][1] = malloc(sizeof(char)*50);
		strcpy((char *)db[a][0],"EMPTY");
		strcpy((char *)db[a][1],"");
	}
	part1 = malloc(sizeof(char)*20);
	part2 = malloc(sizeof(char)*20);
	cmp = malloc(sizeof(char)*20);
		
	strcpy(data,"");
	strcpy(nextdata,"");
	
	if ( ( myfile = fopen("output.txt","w")) != NULL){
	}
	fclose(myfile);
		
		if( myfile = fopen(filename,"r+") ){
			fseek(myfile,-1,SEEK_END);
			fscanf(myfile,"%c",&gett);
		if(gett!='\n'){
				fseek(myfile,0,SEEK_END);
				fprintf(myfile,something);	
			}
		}
		fclose(myfile);
	
	if ( ( myfile = fopen(filename,"r")) == NULL){
			
			printf("Komut dosyasi acilirken bir sorun olustu !\n");
			printFile("%s\n","Komut dosyasi acilirken bir sorun olustu !");
		
	}else{
	
		while ( !feof(myfile) ){
			fscanf(myfile ,"%c",&get_char);
			
			if(get_char == '\n'){
			    
			    for(mm=0;mm<10;mm++){
			        strcpy(WORDS[mm],"");
			    }
			    
				k=0;
				LINE[i] = '\0';
				printf("%s\n",LINE);
				printFile("%s\n",LINE);
				splt = strtok(LINE," ");
				
				while ( (splt) != NULL)	{
					strcpy(WORDS[k],splt);
					splt = strtok(NULL," ");
					k++;
				}
				
				if( strcmp(WORDS[0],"create") == 0 ){
					
					for(l=0;l<k;l++){
					if(strcmp(trim(WORDS[l],NULL),"-n") == 0){
						n = l;
					}else if(strcmp(trim(WORDS[l],NULL),"-t") == 0){
						t = l;
					}
				}
				
				strcpy(name,WORDS[n+1]);
				empty=0;
				
				if(t == 0 || n == 0){
					printf("There is an error Code#01\n");
					printFile("%s\n","There is an error Code#01\n");
				}else if( t-1 == n || n-1 == t || k-1 == t ){
					strcpy(data,"");
					empty=1;
				}else if( n > t){
					for(l=t+1;l<n;l++){
						if(l==n-1){
							strcat(data,WORDS[l]);
						}else{
							strcat(data,WORDS[l]);
							strcat(data," ");
						}
					}
				}else if( t < k){
					for(l=t+1;l<k;l++){
						if(l==k-1){
							strcat(data,WORDS[l]);
						}else{
							strcat(data,WORDS[l]);
							strcat(data," ");
						}
					}
				}
				
				for(a=0;a<100;a++){
					if( strcmp(db[a][0],"EMPTY") == 0){
						db[a][0] = realloc(db[a][0],sizeof(char)*getSize(name));
						db[a][1] = realloc(db[a][1],sizeof(char)*(getSize(data)+empty));
						strcpy((db[a][0]),name);
						strcpy((db[a][1]),data);
						special = a;
						break;
					}
				}
				
				}else if( strcmp(WORDS[0],"delete") == 0 ){
					
					for(f=0;f<k;f++){
						if(strcmp(trim(WORDS[f],NULL),"-n")==0){
							delete_i = f;
							break;
						}
					}
					
					strcpy(name,WORDS[delete_i+1]);
					
					for(f=0;f<100;f++){
						if(strcmp(trim(db[f][0],NULL),trim(name,NULL))==0){
							free(db[f][0]);
							free(db[f][1]);
							db[f][0] = malloc(sizeof(char)*getSize("EMPTY"));
							db[f][1] = malloc(sizeof(char)*1);
							strcpy(db[f][0],"EMPTY");
							strcpy(db[f][1],"");
							break;
						}
					}
					
				}else if( strcmp(WORDS[0],"remove") == 0  ){
									
					for(f=0;f<k;f++){
						if( strcmp(trim(WORDS[f],NULL),"-n") == 0){
							remove_n = f;
						}else if( strcmp(trim(WORDS[f],NULL),"-s") == 0 ){
							remove_s = f;
						}else if( strcmp(trim(WORDS[f],NULL),"-l") == 0){
							remove_l = f;
						}
					}
						
					strcpy(name,WORDS[remove_n+1]);
					
					for(f=0;f<100;f++){
						if(strcmp(trim(db[f][0],NULL),trim(name,NULL)) == 0){
							there=1;
							break;
						}else{
							there = 0;
						}
					}
					
					if(there==1){
						
						start = atoi(WORDS[remove_s+1]);
						length = atoi(WORDS[remove_l+1]);
						end = start + length;
						
						for(f=0;f<100;f++){
							if(strcmp(trim(db[f][0],NULL),trim(name,NULL)) == 0){
								key = f;
								strcpy(data,db[f][1]);
								break;
							}
						}
						
						for(f=0;f<sizeof(data)/sizeof(char);f++){
							if(data[f]=='\0'){
								break;
							}
							if(f>=start && f<end){
								
							}else{
								newdata[cc] = data[f];
								cc++;	
							}
						}
						newdata[cc] = '\0';
						db[key][0] = realloc(db[key][0],sizeof(char)*getSize(newdata));
						strcpy(db[key][1],newdata);
						cc = 0;
					}
					
				}else if ( strcmp(WORDS[0],"append") == 0  ){
					
					for(p = 0; p < k ; p++ ){
						if(strcmp(trim(WORDS[p],NULL),"-n") == 0){
							append_n = p;
						}else if(strcmp(trim(WORDS[p],NULL),"-t") == 0){
							append_t = p;
						}
					}
					
					strcpy(name,WORDS[append_n+1]);
					
					if(append_n > append_t){
						
						for(f = append_t+1 ; f<append_n;f++){
							if(f==append_n-1){
								strcat(data,WORDS[f]);
							}else{
								strcat(data,WORDS[f]);
								strcat(data," ");
							}
						}
						
					}else if(append_t > append_n){
						
						for(f = append_t+1 ; f<k;f++){
							if(f==append_t-1){
								strcat(data,WORDS[f]);
							}else{
								strcat(data,WORDS[f]);
								strcat(data," ");	
							}					
						}	
					}
					
					for(f=0;f<100;f++){
						if(strcmp(trim(db[f][0],NULL),trim(name,NULL)) == 0){
							db[f][1] = realloc(db[f][1],sizeof(char)*(getSize(db[f][1])+getSize(data)));
							strcat(db[f][1],data);
						}
					}
					
				} else if(  strcmp(WORDS[0],"replace") == 0   ){
					
					for(f = 0 ; f < k ; f++){
						if(strcmp(trim(WORDS[f],NULL),"-n") == 0){
							replace_n = f;
						}else if(strcmp(trim(WORDS[f],NULL),"-ow") == 0){
							replace_ow = f;
						}else if(strcmp(trim(WORDS[f],NULL),"-nw") == 0){
							replace_nw = f;
						}
					}
					
					strcpy(oldword,trim(WORDS[replace_ow+1],NULL));
					strcpy(newword,trim(WORDS[replace_nw+1],NULL));
					strcpy(name , WORDS[replace_n+1]);
					oldword[getSize(oldword)+1]='\0';
					newword[getSize(newword)+1]='\0';
					
					for(f = 0 ; f < 100; f++ ){
						if(strcmp(trim(db[f][0],NULL),trim(name,NULL)) == 0 ){
						    
							ok=1;
							key = f;
							break;
						}else{
							ok=0;
						}
					}
					
					if(ok==1){
						strcpy(data,db[key][1]);
						neudata = change(data,oldword,newword);
						db[key][1] = realloc(db[key][1],sizeof(char)*getSize(neudata));
						strcpy(db[key][1],neudata);	
					}
					
				} else if(  strcmp(WORDS[0],"print") == 0   ){
				    
				    
					if ( strcmp(trim(WORDS[1],NULL),"-a") == 0 ){
						
						for(f = 0 ; f < 100 ; f++){
							if( strcmp(trim(db[f][0],NULL),"EMPTY") != 0){
								ct++;
							}
						}
						if(ct>0){
								
							for(f = 0 ; f < 100 ; f++){
								if( strcmp(trim(db[f][0],NULL),"EMPTY") != 0){
									f_keep = f+1;
									printf("Filename %d: %s\n",f_keep,db[f][0]);
									printFile2("Filename %d: %s\n",f_keep,db[f][0]);
								}
							}
							
						}
						
					}else if ( strcmp(trim(WORDS[1],NULL),"-e") == 0){
						
						for(f = 0 ; f < 100 ; f++){
							
							if(strcmp(trim(db[f][0],NULL),"EMPTY")!=0){
								kp++;
							}
							strcpy(holdx,db[f][0]);
							
							psh = strtok(holdx,".");
							strcpy(part1,psh);
							while( psh != NULL ){
								strcpy(part2,psh);
								psh = strtok(NULL,".");
							}
							
							if( strcmp(trim(part2,NULL),trim(WORDS[2],NULL)) == 0 ){
								strcpy(name,db[f][0]);
								strcpy(data,db[f][1]);
								printf("Filename %d: %s\nText: %s\n",kp,part1,data);
								printFile3("Filename %d: %s\nText: %s\n",kp,part1,data);
							}
								
						}
						
					}else if( strcmp(trim(WORDS[1],NULL),"-c") == 0 ){
					    
						for(f = 0 ; f < 100 ; f++){
							if( strcmp(trim(db[f][0],NULL),"EMPTY") != 0){
								km = f + 1;
								strcpy(name,db[f][0]);
								strcpy(data,db[f][1]);
								if(strcmp(data,"")==0 || strcmp(data," ")==0){
									strcpy(data,"Empty File");
								}
								aff = strtok(name,".");
								strcpy(part1,aff);
								while(aff!=NULL){
									strcpy(part2,aff);
									aff = strtok(NULL,".");
								}
								printf("Num: %d\nName: %s\nText: %s\n",km,part1,data);
								printFile3("Num: %d\nName: %s\nText: %s\n",km,part1,data);
								strcpy(name,"");
								strcpy(data,"");
							}
						}
						
					}else if( strcmp(trim(WORDS[1],NULL),"-n") == 0){
						print_t = 0;
						print_cw = 0;
						print_cs = 0;
						
						strcpy(name,trim(WORDS[2],NULL));
						
						for(f=0;f<k;f++){
							if(strcmp(trim(WORDS[f],NULL),"-t")==0){
								print_t = 1;
							}else if(strcmp(trim(WORDS[f],NULL),"-cw")==0){
								print_cw = 1;
								print_cw_data = f;
							}else if(strcmp(trim(WORDS[f],NULL),"-cs")==0){
								print_cs = 1;
								print_cs_data = f;
							}
						}
						
						
						if(print_t == 1){
							
							for(f = 0;f < 100; f++){
							    
								if( strcmp(trim(db[f][0],NULL),name) == 0 ){
									printf("Text: %s\n",db[f][1]);
									printFile("Text: %s\n",db[f][1]);
								}
							}
							
						}else if(print_cw == 1){
						    
							for(f = 0;f < 100; f++){
								if( strcmp(trim(db[f][0],NULL),trim(name,NULL)) == 0 ){
								    strcpy(holdd,"");
								    strcpy(trim(holdd,NULL),trim(WORDS[print_cw_data+1],NULL));
									count_words = search(db[f][1],holdd);
                				    printf("Text: %s \n",db[f][1]);
                				    printf("Number of Occurence of \"%s\" : %d\n",holdd,count_words);
									printFile4("Text: %s \nNumber of Occurence of : %d\n",db[f][1],WORDS[print_cw_data+1],count_words);
								}
							}
							count_words = 0;
						}else if(print_cs == 1){
							
							for(f=0;f<100;f++){
								if( strcmp(trim(db[f][0],NULL),trim(name,NULL)) == 0 ){
									strcpy(data,db[f][1]);
									for(f=0;f<sizeof(data)/sizeof(char);f++){
										if(data[f] == '\0'){
											break;
										}
										if(data[f] == '!'){
											count_sentences++;
										}
										if(data[f] == '?'){
											count_sentences++;
										}
										if(data[f] == '.'){
											count_sentences++;
										}
									}
									printf("Text: %s\nNumber Of Sentences : %d\n",data,count_sentences);
									printFile5("Text: %s\nNumber Of Sentences : %d\n",data,count_sentences);
								}
							}
							count_sentences = 0;
						}
						
					}
					
				}
				
				strcpy(data,"");
				strcpy(newdata,"");
				strcpy(name,"");
				for(m=0;m<10;m++){
					strcpy(WORDS[m],"");	
				}
				strcpy(LINE,"");
				i=0;
			}else{
				LINE[i] = get_char;
				i++;
			}
			
		}
	}
	
}

int main(int argc,char *argv[]){
	doIt(argv[1]);
	return 0;
}
