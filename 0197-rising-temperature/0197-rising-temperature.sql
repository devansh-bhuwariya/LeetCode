# Write your MySQL query statement below
SELECT w1.id FROM Weather w, Weather w1
WHERE DATEDIFF(w1.recordDate,w.recordDate)=1 and w1.temperature>w.temperature;