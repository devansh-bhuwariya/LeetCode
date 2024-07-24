# Write your MySQL query statement below
SELECT Distinct(l1.num) AS ConsecutiveNums FROM Logs l1, Logs l2, Logs l3
WHERE l1.num=l2.num 
    and l1.num=l3.num 
    and l1.id=l2.id-1 
    and l1.id=l3.id-2;