//============================================================================
// Name        : Affinity 
// Description : Compatibility test, Audience targeting, Customers profiling
// Version     : 1.0
// Language     : C++
// Copyright   : Co. 2011-2013
// Author      : Habib
// Email	   : habiboulaye@gmail.com
//============================================================================
//============================================================================
// PROBLEM STATEMENT
// You are in-charge of the office jukebox. You are determined to do a
// very good job and make your colleagues happy. You ask all of them to
// email you a list of music bands they like. The number of bands each
// colleague likes is limited to 10,000.

// INPUT
// All input will be given on stdin. Your input will be of the form,
// 1. The first line will be an integer stating the number of lines of input.
// 2. The input will only contain alphanumeric characters, colon, comma,
// underscore and space [A-Za-z0-9_, ]+.
// 3. The first word will be the name of your colleague, followed by a colon.
// 4. A comma separated list of that person’s favourite bands will follow the colon.
// 5. Every line will be terminated by a newline character (\n).

// An example input would look like -
6
Anne: Metallica, The_Doors, Black_Sabbath
John: The_Beatles, The_Doors, Metallica, Pink_Floyd
Kathy: U2, Guns_n_Roses, Led_Zeppelin
Jamie: Radiohead
Ashok: Guns_n_Roses, U2, Pink_Floyd, The_Doors
Sara: Blink_182, Iron_Maiden, The_Doors

//============================================================================
// PROBLEM 1
// Write a program to find the top 2 liked bands. If there is a tie, output
// all the matching bands. Each band should be on a new line. The output
// order is unimportant. For the example input above, the output will be,
The_Doors
Metallica
Pink_Floyd
U2
Guns_n_Roses

// PROBLEM 2
// You want to determine band following. Write a program to output
// the band name followed by the colleagues who like the band. 
// For our example input, this would be,
Metallica: Anne, John
The_Doors: Anne, John, Ashok, Sara
Black_Sabbath: Anne
The_Beatles: John
Pink_Floyd: John, Ashok
U2: Kathy, Ashok
Guns_n_Roses: Ashok, Kathy
Led_Zeppelin: Kathy
Radiohead: Jamie
Blink_182: Sara
Iron_Maiden: Sara

// PROBLEM 3
// Your colleagues are happy if they can listen to their liked band at least
// once a day. Assuming,
// 1. Each song lasts for 5 mins.
// 2. You have only 1 song from each band in your playlist.
// 3. A work day lasts 8 hours.
// Write a program to maximize the number of happy people in your office.
// If there are multiple correct outputs, output any one. Your output
// should be a list of artists separated by a new line (order unimportant).
// For our example, one of the valid outputs is,
The_Doors
U2
Radiohead

// PROBLEM 4
// You decide to use your data to find the people most compatible with
// each other. Two people are compatible if they have at least 2 bands in
// common. The compatibility of two people is directly proportional to
// the number of bands they like in common.
// For each person in the list, output the most compatible person(s).
// If there is more than one compatible person, separate the names with
// a comma. If a person has nobody compatible, output nothing.
// For our example input, the output will be,
Anne: John
John: Anne, Ashok
Kathy: Ashok
Jamie:
Ashok: John, Kathy
Sara:
