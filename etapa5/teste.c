int a;
int g(int x){
	x = 5;
	return x + 1;
}
int main(){
	a = 0;
	a = g(a);
}
