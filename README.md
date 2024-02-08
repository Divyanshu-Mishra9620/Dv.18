# Dv.18
<p>->Allot n books to m students contagiously and each should get atleast 1 book.</p>
<br>
<br>
<p>DESCRIPTION</p>
<br><br>
<p>You have N books, each with A[i] number of pages. M students need to be allocated contiguous books, with each student getting at least one book.
Out of all the permutations, the goal is to find the permutation where the sum of maximum number of pages in a book allotted to a student should be minimum, out of all possible permutations.
</p>
<br>
<p>
Input:
<br>
N = 4
<br>
A[] = {12,34,67,90}
<br>
M = 2
<br>
Output:113
<br>
Explanation:Allocation can be done in 
following ways:
<br>
{12} and {34, 67, 90} Maximum Pages = 191
<br>
{12, 34} and {67, 90} Maximum Pages = 157
<br>
{12, 34, 67} and {90} Maximum Pages =113.
<br>
Therefore, the minimum of these cases is 113,
which is selected as the output.
<br>
</p>
<br><br>
<p>APPROACH</p>
<br><br>
<p>Using binary search, we will define the search space which will be between 0 to 203 (12+34+67+90)
<br> 
start=0 and end = 203
<br>
mid = (0+203)/2=101 , now we will try to allocate each student atmost 101 pages.
<br>
case-I
<br>allocate 12 , 34 but as we will further give 67 the sum will be 113 which is greater than 101. 12+34 < 101
<br>
case-II
<br>
allocate 67 and 90 to the other student but again when we will try to allocate 90 to the 2nd student the sum will exceed 101. 67 < 101
<br>
case-III
<br>
we are going to allocate the 90 to third student but as we have only 2 student ,therefore this solution is not possible. 90 < 101
<br><br>
start = mid + 1 ,
end = 203 and 
mid = (102 + 203) / 2 = 152
<br>
We have to allocate at mot  152
<br>
case-I
<br>
 allocate 12, 34 and 67 to the first student but when will try to allocate 90 pages the sum will exceed 152. 12 + 34 + 67 < 152
<br>
case-II
<br>
allocate 90 to the 2nd student. 90 < 152
<br>
It can be the possible solution ,but as the question asks to find the minimum pages. We will check if pages less than 152 is possible.
<br><br>
start = 102 , end = mid - 1 and mid=(start + end)/2
(102 + 151) / 2 = 126 
<br>
case-I
<br>12 + 34 + 67 = 113 < 126
<br>
case-II
<br>
90 < 126
<br>
update the answer to 126 and check if pages less than 126 is possible or not.
<br><br>
start = 102 , end = mid - 1 = 125 and mid =(102+125)/2=113
<br>
case-I
<br>
12 + 34 + 67 = 113
<br>
case-II
<br>
 90 < 113
<br>
Update the answer to 113 and check further
<br><br>
start = 102, end = mid - 1 = 112, mid=(102+112)/2=107
<br>
case-I
<br>
12 + 34 + 67 > 107 so allocate the 67 pages to the other student 12 + 34 < 107
<br>
case-II
<br>
67 + 90 > 107 ,allocate the 90 pages to other student but as there are only two student so this solution is not possible. Pages has to be more than 107
<br> 
last updated answer is 113
<br><br>
start = mid + 1 = 107+1=108 , end = 112, mid = (108+112)/2=110
<br>
case-I
<br>
12 + 34 < 110
<br>
case-II
<br>
67 < 110, 90 is left which cant be allocated so this is also not possible solution.
<br><br>
start = mid + 1 = 111, end = 112, mid =(111+112)/2=111
<br>
Again this is not possile
<br><br>
start = mid + 1 = 112, end = 112 , mid = 112
<br>
Not a possible solution
<br><br>
start = mid + 1 = 112 + 1 = 113 > end (start > end) breaking condition.
<br><br>
We will come out of loop and as last updated answer was 113 therefore minimum number of pages tha are possible is 113.
</p>
