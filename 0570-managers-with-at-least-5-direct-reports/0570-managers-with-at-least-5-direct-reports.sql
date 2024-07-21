# Write your MySQL query statement below
SELECT e2.name FROM Employee AS e1
LEFT JOIN Employee AS e2 ON e1.managerId=e2.id
GROUP BY e2.id HAVING count(e2.id)>=5;