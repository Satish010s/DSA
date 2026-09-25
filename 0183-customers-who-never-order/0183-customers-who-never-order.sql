# Write your MySQL query statement below
SELECT s.name AS Customers FROM 
Customers s
LEFT JOIN Orders o ON s.id=o.customerId
WHERE o.customerId IS NULL;