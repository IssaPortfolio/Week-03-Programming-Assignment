Write a Item Shipping Calculator program that does the following:

Prompt and retrieve the following input from the user (through the console):

    • Item name
  
    • Is the item fragile (add in $2.00 if the item is fragile)
  
    • The order total (without shipping)
  
    • The destination to which the item will be shipped (USA, Canada, Australia)  
  
  
Use the following table to determine the calculations to perform:

               
|    Order Total:    | Ship to USA: | Ship to Canada: | Ship to Australia: |
|--------------------|--------------|-----------------|--------------------|
| Less Than $50.00   | $6.00        | $8.00           | $10.00             |
|                    |              |                 |                    |
| $50.01 to $100.00  | $9.00        | $12.00          | $14.00             |
|                    |              |                 |                    |
| $100.01 to $150.00 | $12.00       | $15.00          | $17.00             |
|                    |              |                 |                    |
| Over $150.00       | Free         | Free            | Free               |

  
    • If the item is fragile add $2.00 to the shipping cost.
