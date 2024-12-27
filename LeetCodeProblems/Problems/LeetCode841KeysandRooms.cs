namespace LeetCodeProblems.Problems;

public class LeetCode841KeysandRooms : BaseProblemClass
{
    public bool CanVisitAllRooms(IList<IList<int>> rooms)
    {
        int roomCount = rooms.Count;
        bool[] visited = new bool[roomCount];
        int visitedCount = 0;
        Queue<int> roomsToVisit = [];
        Queue<int> nextRoomsToVisit = [];
        roomsToVisit.Enqueue(0);
        IList<int> keys = new List<int>();
        int currentRoom = 0;
        while (roomsToVisit.Count > 0)
        {
            while (roomsToVisit.Count > 0)
            {
                currentRoom = roomsToVisit.Dequeue();
                if(visited[currentRoom])
                    continue;
                visited[currentRoom] = true;
                visitedCount++;
                if (visitedCount == roomCount)
                    return true;
                keys = rooms[currentRoom];
                foreach (var key in keys)
                {
                    if (visited[key])
                        continue;
                    nextRoomsToVisit.Enqueue(key);
                }
            }

            while (nextRoomsToVisit.Count>0)
            {
                roomsToVisit.Enqueue(nextRoomsToVisit.Dequeue());
            }
        }

        return false;
    }

    public override void Run()
    {
        IList<IList<int>> rooms = [[1, 3], [3, 0, 1], [2], [0]];
        CanVisitAllRooms(rooms);
    }
}