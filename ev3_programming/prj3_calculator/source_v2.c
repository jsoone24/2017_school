task main()
{
	int num[] = {2, 0, 1, 7, 0, 0, 0, 0};
	int sum, gob;
	float nanum;

	sum = num[6] + num[7];
	gob = sum * num[5];
	nanum = gob / 7;

	displaytextline(1, "0+4 = %d", sum);		 // sum = 4
	displaytextline(3, "%d*4 = %d", sum, gob);	 // gob = 16
	displaytextline(5, "%d/7 = %f", gob, nanum); // nanum = 2.2857142857
	displaytextline(7, "%d%d%d%d%d%d%d%d", num[0] > num[0], num[1] > num[0], num[2] > num[0], num[3] > num[0], num[4] > num[0], num[5] > num[0], num[6] > num[0], num[7] > num[0]);
	sleep(150000);
}