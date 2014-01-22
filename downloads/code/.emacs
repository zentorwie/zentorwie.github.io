(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.

 ;; #MY EDIT BEGIN#
 ;; Load fancy theme 'wombat
 '(custom-enabled-themes (quote (wombat)))

 ;; Hide the tool bar
 '(tool-bar-mode nil)

 ;; Set flash-screen Alarm
 '(visible-bell t)

 ;; Hide scroll-bar
 '(scroll-bar-mode nil)

 ;; Display column number
 '(column-number-mode t)

 ;; Yank at point instead of mouse cursor
 '(mouse-yank-at-point t)

 ;; Set a big killing-ring
 '(kill-ring-max 200)


 ;; Set MY Coding Style (Indentation : 2, based on awk-style)
 '(c-default-style "awk")
 '(c-basic-offset 2)

 '(default-fill-column 60)
 '(scroll-margin 3)
 '(scroll-conservatively 10000)
 '(user-full-name "Dongyu Zeng")
 '(user-mail-address "zentorwie@gmail.com")
 '(version-control t)
 '(kept-new-versions 3)
 '(delet-old-versions t)
 '(kept-old-versions 2)
 '(dired-kept-versions 1)

 '(show-paren-mode t)
 '(show-paren-style 'parentheses)

 ;; #MY EDIT END#

 '(custom-safe-themes (quote ("c9c9b8f2e2ab9769ab6ab394725e3f29e8e70853863c5a32be42058b69a646fe" default))))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(default ((t (:family "Ubuntu Mono" :foundry "unknown" :slant normal :weight normal :height 120 :width normal))))
 '(font-lock-type-face ((t (:foreground "deep sky blue" :weight bold)))))
