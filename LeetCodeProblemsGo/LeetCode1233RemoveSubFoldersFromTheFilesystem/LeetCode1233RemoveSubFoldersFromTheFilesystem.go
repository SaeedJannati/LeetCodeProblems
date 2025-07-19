package LeetCode1233RemoveSubFoldersFromTheFilesystem

func removeSubfolders(folder []string) []string {
	root := &TrieNode{
		IsFolder:   false,
		FolderName: "",
		Children:   make(map[string]*TrieNode),
	}
	for _, f := range folder {
		folderNames := getSubFolders(f)
		addFolder(root, folderNames)
	}
	result := []string{}
	dfs(root, "", &result)
	return result
}
func dfs(node *TrieNode, currnetPath string, result *[]string) {
	if len(node.FolderName) > 0 {
		currnetPath += "/" + node.FolderName
	}

	if node.IsFolder {
		*result = append(*result, currnetPath)
		return
	}
	for _, childNode := range node.Children {
		dfs(childNode, currnetPath, result)
	}
}
func getSubFolders(folder string) []string {
	result := make([]string, 0)
	buffer := ""
	length := len(folder)
	for i := 0; i < length; i++ {
		if folder[i] == '/' {
			if buffer != "" {
				result = append(result, buffer)
			}
			buffer = ""
		} else {
			buffer += string(folder[i])
		}
	}
	if buffer != "" {
		result = append(result, buffer)
	}
	return result
}
func addFolder(root *TrieNode, flodersInPath []string) {
	node := root
	for _, folder := range flodersInPath {
		if node.Children == nil {
			node.Children = make(map[string]*TrieNode)
		}
		if _, exists := node.Children[folder]; !exists {
			newNode := &TrieNode{
				IsFolder:   false,
				FolderName: folder,
				Children:   make(map[string]*TrieNode),
			}
			node.Children[folder] = newNode
			node = newNode
			continue
		}
		node = node.Children[folder]
	}
	node.IsFolder = true
}

type TrieNode struct {
	IsFolder   bool
	FolderName string
	Children   map[string]*TrieNode
}
