//This function is going to sort batteries

void sortBatteries(Battery * arr, int len) {

Battery a;
  for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i].getTotal() > arr[j].getTotal())
            {
                a =  arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }
}

