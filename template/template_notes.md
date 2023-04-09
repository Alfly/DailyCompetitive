## [name]()

> Tag: 

### 方法一：

```c++

```

### 方法二：

```c++

```

## snippet setting in vscode

`markdown.json`: snippet setting
```json
	"Make code notes here": {
		"prefix": "notes",
		"body": [
			"## [name]()",
			"",
			"> Tag: ",
			"",
			"### 方法一：",
			"",
			"```c++",
			"",
			"```",
			"",
			"### 方法二：",
			"",
			"```c++",
			"",
			"```"
		],
		"description": "Make code notes here"
	}
```

`setting.json`: allow quick quickSuggestions in `*.md` files
```json
    "[markdown]": {
        "editor.quickSuggestions": {
          "other": true,
          "comments": true,
          "strings": true
        }
    }
```