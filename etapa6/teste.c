int main() {
	int a;
	a = 0;
	int i;
	for(i=0: i < 6: i=i+1){
		a = a + 1;
		if(a==2) {
			return 2;
		}
	}
	return a;
}