/**************************************************************/
/*                 Author    : Muhammad Ali Habash            */
/*                 Version   : 1.0                            */
/*                 Date      : 12/27/2021                     */
/*                 Last Edit : N/A                            */
/**************************************************************/

#include "BINARY_search.h"

int8_t binarySearch (uint32_t* arr, uint8_t size, uint32_t number)
{
	uint8_t u8_Mid, u8_Start, u8_End;
	
	bubbleSort(arr, size);
	u8_Start = 0;
	u8_End   = size - 1;
	u8_Mid   = ( (u8_Start + u8_End) / 2 );
	if (number < arr[0] || number > arr[size - 1])
	{
		return -1;
	}
	else
	{
	    while (u8_Start <= u8_End)
	    {
	        if (arr[u8_Mid] == number)
	        {
		        return u8_Mid;
	        }
	        else if (number > arr[u8_Mid])
	        {
		        u8_Start = u8_Mid + 1;
		        u8_Mid   = ( (u8_Start + u8_End) / 2 );
	        }
	        else
	        {
		        u8_End = u8_Mid - 1;
		        u8_Mid = ( (u8_Start + u8_End) / 2 );
	        }
	    }
	    return -1;
	}
}

void bubbleSort (uint32_t* au32_Arr, uint8_t u8_Size)
{
	uint8_t u8_Pass, u8_ComparedElement;
	uint32_t u32_Temp;
	
	for ( u8_Pass = 0 ; u8_Pass < u8_Size - 1 ; u8_Pass++ )
	{
		for ( u8_ComparedElement = 0; u8_ComparedElement < (u8_Size - u8_Pass) - 1 ; u8_ComparedElement++ )
		{
			if (au32_Arr[u8_ComparedElement] > au32_Arr[u8_ComparedElement + 1])
			{
				u32_Temp                         = au32_Arr[u8_ComparedElement];
				au32_Arr[u8_ComparedElement]     = au32_Arr[u8_ComparedElement + 1];
				au32_Arr[u8_ComparedElement + 1] = u32_Temp;
			}
		}
	}
}

uint8_t main()
{
	uint8_t u8_Size, u8_Counter, u8_Index;
	uint32_t* au32_Arr;
	uint32_t u32_Number, u32_SearchNumber;
	printf("\nEnter the size of the array: ");
	scanf("%d",&u8_Size);
	au32_Arr = (uint32_t*) malloc(u8_Size * sizeof(uint32_t));
	for(u8_Counter = 0 ; u8_Counter < u8_Size ; u8_Counter++)
	{
		printf("\nEnter element number %d: ",u8_Counter+1);
		scanf("%d",&u32_Number);
		au32_Arr[u8_Counter] = u32_Number;
	}
	printf("\nEnter the number you want to search for: ");
	scanf("%d",&u32_SearchNumber);
	
	if(binarySearch(au32_Arr,u8_Size,u32_SearchNumber) == -1)
	{
		printf("\nNot found");
	}
	else
	{
		u8_Index = binarySearch(au32_Arr,u8_Size,u32_SearchNumber);
        printf("\nThe number you entered was found in index number %d",u8_Index);		
	}
	return 0;
}

