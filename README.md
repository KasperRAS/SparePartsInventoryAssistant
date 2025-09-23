# Spare Parts Inventory Assistant
Below you'll find a brief description of the code for the SparePartsInventoryAssistant assignment.

# Task
The task was to build a program which responds to queries by the user.
If the user asks about a part that is listed in a predefined list,
the program will return a positive message about the part being in stock.
If the user other hand queries about any other part it will return a message,
saying that the part is not in stock.
Should the user ask one of two predefined questions,
the program will return a list of items in stock.

# Input / Outputs
Inputs:     - Parts queries
            - Questions about total stock

Outputs:    - Confirmations of item being in stock
            - Message saying item isn't in stock
            - List of total stock

# Messages
All messages are declared outside the logic for easier readability.
This also enables them to be called several times more easily in a larger program.

# Other
A confirm to exit prompt was added to enable the user to actually see the message when a part is in stock.
The program would exit immediately otherwise.