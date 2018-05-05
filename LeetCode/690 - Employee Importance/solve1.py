"""
# Employee info
class Employee:
    def __init__(self, id, importance, subordinates):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates
"""
class Solution:
    def getImportance(self, employees, id):
        """
        :type employees: Employee
        :type id: int
        :rtype: int
        """
        d = {emp.id: emp for emp in employees}
        
        def getImportanceImpl(d, id):
            if not id in d: return 0
            return d[id].importance + sum([getImportanceImpl(d, sub_id) for sub_id in d[id].subordinates])
        
        return getImportanceImpl(d, id)
