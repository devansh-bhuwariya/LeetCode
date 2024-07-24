# Write your MySQL query statement below
SELECT m.employee_id,
       m.name,
       count(m.employee_id) AS reports_count, 
       ROUND(AVG(e.age),0) AS average_age
FROM Employees AS e
INNER JOIN Employees AS m on e.reports_to=m.employee_id
GROUP BY m.employee_id
ORDER BY m.employee_id;