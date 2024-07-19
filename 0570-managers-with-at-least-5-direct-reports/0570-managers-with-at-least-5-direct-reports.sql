SELECT e1.name FROM Employee AS e1
INNER JOIN Employee AS e2 on e1.id=e2.managerId
GROUP BY e2.managerId HAVING count(e2.managerId)>=5;