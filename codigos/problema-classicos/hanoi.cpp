void hanoi(int disco, int origem, int dest, int aux)
{
	if(disco==1)
	{
		ans.pb({origem, dest});
		return;
	}

	// removo o que ta em cima de mim
	hanoi(disco-1, origem, aux, dest);
	ans.pb({origem, dest}); // movo pro destino
	// volto o meu imediato para cima de mim
	hanoi(disco-1, aux, dest, origem);
}